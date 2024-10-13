cmake_minimum_required(VERSION 3.21)

project(solus VERSION 1.0.0 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}\\cmake")

include(GNUInstallDirs)
include(IncludedScripts)

include_directories(${CMAKE_SOURCE_DIR}\\include)

set(sources ${SOURCES}
  src/solus.cpp
  src/engine.cpp)

find_package(CommonLibSSE CONFIG REQUIRED)
add_commonlibsse_plugin(
  ${PROJECT_NAME}
  SOURCES ${sources}
  USE_ADDRESS_LIBRARY
  USE_SIGNATURE_SCANNING)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}\\include\\PCH.h)

find_package(lua CONFIG REQUIRED)
find_package(sol2 CONFIG REQUIRED)
add_subdirectory(extern/simdjson EXCLUDE_FROM_ALL)

target_link_libraries(${PROJECT_NAME} PRIVATE simdjson lua sol2)

# TODO: add hashing of all files in lib/*.lua and add them to the target via a header file
# TODO: I'd like to compile .yue files into .lua files JIT but the CMakeLists file for yuescript is broken for import

if (DEFINED ENV{SKYRIM_FOLDER} AND IS_DIRECTORY "$ENV{SKYRIM_FOLDER}\\Data")
    set(OUTPUT_FOLDER "$ENV{SKYRIM_FOLDER}\\Data")
endif ()

if (DEFINED ENV{SKYRIM_MODS_FOLDER} AND IS_DIRECTORY "$ENV{SKYRIM_MODS_FOLDER}")
    set(OUTPUT_FOLDER "$ENV{SKYRIM_MODS_FOLDER}\\${PROJECT_NAME} ${CMAKE_BUILD_TYPE}")
endif ()

if (DEFINED OUTPUT_FOLDER)
    # If you specify an <OUTPUT_FOLDER> (including via environment variables)
    # then we'll copy your mod files into Skyrim or a mod manager for you!

    # Copy the SKSE plugin .dll files into the SKSE/Plugins/ folder
    set(DLL_FOLDER "${OUTPUT_FOLDER}\\SKSE\\Plugins")

    message(STATUS "SKSE plugin output folder: ${DLL_FOLDER}")

    add_custom_command(
        TARGET "${PROJECT_NAME}"
        POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E make_directory "${DLL_FOLDER}"
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:${PROJECT_NAME}>" "${DLL_FOLDER}/$<TARGET_FILE_NAME:${PROJECT_NAME}>"
        VERBATIM
    )

    # If you perform a "Debug" build, also copy .pdb file (for debug symbols)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_custom_command(
            TARGET "${PROJECT_NAME}"
            POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_PDB_FILE:${PROJECT_NAME}>" "${DLL_FOLDER}/$<TARGET_PDB_FILE_NAME:${PROJECT_NAME}>"
            VERBATIM
        )
    endif ()

    compile_included_scripts("${DLL_FOLDER}")
endif ()