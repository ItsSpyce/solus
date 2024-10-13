function (compile_yue_scripts OUT_DIR)
  add_custom_command(
    TARGET "${PROJECT_NAME}"
    POST_BUILD
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/yue.exe -m -t ${OUT_DIR} .
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    COMMENT "Compiling Yue scripts"
  )
endfunction ()