cmake_minimum_required(VERSION 3.1.0)
project(libKernel)

set(libKernel_SRCS
    Kernel.h
)

# Declare the library
add_library(libKernel STATIC
    ${libKernel_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(libKernel PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)