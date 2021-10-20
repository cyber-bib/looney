
add_library(looney_function-obj OBJECT)
target_sources(looney_function-obj
  PRIVATE
    series.fxx
    series.hxx
    series.txx
    series.cxx
)
target_include_directories(looney_function-obj
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)