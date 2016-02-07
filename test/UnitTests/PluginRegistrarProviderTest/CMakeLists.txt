cmake_minimum_required(VERSION 3.1.0)
project (PluginArch_PluginRegistrarProviderTest)

file(GLOB SRCS *.cpp *.h)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
	libPluginRegistrarProvider
    libgtest
    libgmock
)

add_test(NAME ${PROJECT_NAME}
         COMMAND ${PROJECT_NAME})