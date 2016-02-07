cmake_minimum_required(VERSION 3.1.0)
project(UserCase01 C CXX)

file(GLOB SRCS *.cpp *.h ../main.cpp)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    libgtest
    libgmock
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_test(NAME ${PROJECT_NAME}
         COMMAND ${PROJECT_NAME})