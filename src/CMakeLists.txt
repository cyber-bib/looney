cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(looney-core
	VERSION 0.0.0.1
	DESCRIPTION "Machine Force-Simulation Object Base Class"
	HOMEPAGE_URL "..."
  LANGUAGES C CXX
)
set(VTK_DIR "C:/dev/vtk/build/windows/VS16/Install/Release/lib/cmake/vtk-9.0")
find_package(VTK
	COMPONENTS
		vtkChartsCore
		vtkCommonColor
		vtkCommonCore
		vtkCommonDataModel
		vtkInteractionStyle
		vtkRenderingContext2D
		vtkRenderingContextOpenGL2
		vtkRenderingCore
		vtkRenderingFreeType
		vtkRenderingGL2PSOpenGL2
		vtkRenderingOpenGL2
		vtkViewsContext2D
	REQUIRED
	)

# add_subdirectory(tensor)
add_subdirectory(function)
# add_subdirectory(series)
# add_subdirectory(derivative)
add_subdirectory(vtk-interface)

add_executable(looney main.cxx)
target_link_libraries(looney
	PRIVATE
		looney_function-obj
		# looney_derivate-obj
		looney_interface-obj
		${VTK_LIBRARIES}
	)
vtk_module_autoinit(
	TARGETS looney
	MODULES ${VTK_LIBRARIES}
	)