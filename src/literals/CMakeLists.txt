
add_library(looney_literals-obj OBJECT)
target_sources(looney_literals-obj
  PRIVATE
    literals.hxx
    literals.cxx
)
target_include_directories(looney_literals-obj
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)