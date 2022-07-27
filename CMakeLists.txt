cmake_minimum_required(VERSION 3.0.0)
project(Basic-algorithm-exercise VERSION 0.1.0)

include(CTest)
enable_testing()

set( CMAKE_CXX_FLAGS "-std=c++14" )

add_executable(Basic-algorithm-exercise src/exercise/ex0014/main.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
