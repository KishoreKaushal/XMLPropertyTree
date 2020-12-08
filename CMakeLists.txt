cmake_minimum_required(VERSION 3.0)
project(XMLPropertyTree)

set(CMAKE_CXX_STANDARD 17)

find_library(XERCESC xerces-c)

file(GLOB SOURCES "*.cpp")

add_executable(XMLPropertyTree ${SOURCES})
target_link_libraries(XMLPropertyTree ${XERCESC})