cmake_minimum_required(VERSION 3.16)
project(Tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tests main.cpp)

target_link_libraries( ${PROJECT_NAME} -lrt)


