cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(looney-proj
	VERSION 0.0.0.1
	DESCRIPTION "CMake Development template project"
	HOMEPAGE_URL "..."
  LANGUAGES C CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Helpers)
add_project_defaults()

add_subdirectory(src core)
