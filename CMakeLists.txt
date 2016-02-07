cmake_minimum_required(VERSION 3.1.0)
project(PluginArch)

if(UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()

enable_testing()

add_subdirectory(test)
add_subdirectory(src)