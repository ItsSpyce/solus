function (compile_teal_scripts OUT_DIR)
  add_custom_command(
    TARGET "${PROJECT_NAME}"
    POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E make_directory "${OUT_DIR}"
  )
  add_custom_command(
    TARGET "${PROJECT_NAME}"
    POST_BUILD
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/tl.exe build -b ${OUT_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
    COMMENT "Generating Teal scripts"
  )
endfunction ()