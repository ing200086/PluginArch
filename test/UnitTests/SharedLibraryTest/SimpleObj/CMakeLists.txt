cmake_minimum_required(VERSION 3.1.0)

file(GLOB SRCS *.cpp *.h)

ADD_LIBRARY(SimpleSharedObject SHARED ${SRCS})