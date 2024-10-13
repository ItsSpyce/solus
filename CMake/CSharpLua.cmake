set(CSHARP_LUA_EXTERN "${CMAKE_SOURCE_DIR}/extern/CSharp.lua")

function (build_csharplua_launcher)
  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(DOTNET_BUILD_CONFIGURATION "Debug")
  else ()
    set(DOTNET_BUILD_CONFIGURATION "Release")
  endif () 
  execute_process(COMMAND dotnet build "${CSHARP_LUA_EXTERN}/CSharp.lua.Launcher/CSharp.lua.Launcher.csproj" -c ${DOTNET_BUILD_CONFIGURATION} -o "${CMAKE_CURRENT_SOURCE_DIR}/bin/CSharp.lua")
endfunction ()

function (compile_csharp_scripts OUT_DIR)
  set(CSHARP_CORE_SYSTEM_DIR "${CSHARP_LUA_EXTERN}/CSharp.lua/CoreSystem.Lua/CoreSystem")
  file(COPY "${CSHARP_CORE_SYSTEM_DIR}" DESTINATION "${OUT_DIR}")
  message(STATUS "Copied ${CSHARP_CORE_SYSTEM_DIR} to ${OUT_DIR}")
  add_custom_command(
    TARGET "${PROJECT_NAME}"
    POST_BUILD
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/CSharp.lua/CSharp.lua.Launcher.exe -s "${CMAKE_SOURCE_DIR}/lib" -d "${OUT_DIR}"
  )
endfunction ()