
add_library(looney_function-obj OBJECT)
target_sources(looney_function-obj
  PRIVATE
    function.fxx
    function.hxx
    function.txx
    function.cxx
)
target_include_directories(looney_function-obj
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)