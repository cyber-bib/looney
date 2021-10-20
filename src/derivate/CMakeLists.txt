
add_library(looney_derivative-obj OBJECT)
target_sources(looney_derivate-obj
  PRIVATE
    derivate.fxx
    derivate.hxx
    derivate.txx
    derivate.cxx
)
target_include_directories(looney_derivative-obj
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(looney
	PUBLIC
		looney_function-obj
  )