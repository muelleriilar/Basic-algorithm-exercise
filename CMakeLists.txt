cmake_minimum_required(VERSION 3.0.0)
project(Basic-algorithm-exercise VERSION 0.1.0)

set( CMAKE_CXX_FLAGS "-std=c++17" )

add_executable(Basic-algorithm-exercise src/solutions/0001.cc)
# add_executable(Basic-algorithm-exercise src/practices/0001.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
