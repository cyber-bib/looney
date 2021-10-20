
add_library(looney_interface-obj OBJECT)
target_sources(looney_interface-obj
  PRIVATE
    vtk-interface.hxx
    vtk-interface.cxx
)
target_include_directories(looney_interface-obj
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(looney_interface-obj
	PRIVATE
		looney_function-obj
		${VTK_LIBRARIES}
	)