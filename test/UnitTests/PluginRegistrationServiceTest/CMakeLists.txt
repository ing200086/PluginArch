cmake_minimum_required(VERSION 3.1.0)
project (PluginArch_PluginRegistrationServiceTest)

file(GLOB SRCS *.cpp *.h ../main.cpp)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
	libPluginRegistrationService
    libgtest
    libgmock
)

add_test(NAME ${PROJECT_NAME}
         COMMAND ${PROJECT_NAME})