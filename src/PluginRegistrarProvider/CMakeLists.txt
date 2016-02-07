cmake_minimum_required(VERSION 3.1.0)
project(libPluginRegistrarProvider C CXX)

file(GLOB SRCS *.cpp *.h)

# Declare the library
add_library(${PROJECT_NAME} STATIC
    ${SRCS}
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# target_link_libraries(${PROJECT_NAME}
# 	libSharedLibraryLoader)

# Specify here the include directories exported
# by this library
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)