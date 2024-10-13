set(SOLUS_COMPILE_YUE OFF CACHE BOOL "Compile yue scripts")
set(SOLUS_COMPILE_TEAL OFF CACHE BOOL "Compile teal scripts")
set(SOLUS_COMPILE_CS OFF CACHE BOOL "Compile c# scripts")

if (SOLUS_COMPILE_YUE)
  message(STATUS "Adding Yue scripts to compilation")
  include(Yue)
endif ()

if (SOLUS_COMPILE_TEAL)
  message(STATUS "Adding Teal scripts to compilation")
  include(Teal)
endif ()

if (SOLUS_COMPILE_CS)
  message(STATUS "Adding C# scripts to compilation")
  include(CSharpLua)
endif ()

function (compile_included_scripts DLL_FOLDER)
  set(SCRIPTS_OUT_DIR "${DLL_FOLDER}/Solus/lib")

  add_custom_command(
    TARGET "${PROJECT_NAME}"
    POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E remove_directory "${SCRIPTS_OUT_DIR}"
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${SCRIPTS_OUT_DIR}"
    VERBATIM
  )

  # Before compiling, copy all .lua files to ${SCRIPTS_OUT_DIR}
  file(GLOB LUA_FILES "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.lua")
  # doing a foreach because if there's too many files, the command line will be too long
  foreach (LUA_FILE ${LUA_FILES})
    get_filename_component(FILE_NAME ${LUA_FILE} NAME)
    add_custom_command(
      TARGET "${PROJECT_NAME}"
      POST_BUILD
      COMMAND "${CMAKE_COMMAND}" -E copy "${LUA_FILE}" "${SCRIPTS_OUT_DIR}/${FILE_NAME}"
      VERBATIM
    )
  endforeach ()

  if (SOLUS_COMPILE_YUE)
    compile_yue_scripts("${SCRIPTS_OUT_DIR}")
  endif ()

  if (SOLUS_COMPILE_TEAL)
    compile_teal_scripts("${SCRIPTS_OUT_DIR}")
  endif ()

  if (SOLUS_COMPILE_CS)
    build_csharplua_launcher()
    compile_csharp_scripts("${SCRIPTS_OUT_DIR}")
  endif ()
endfunction ()