cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME Renderer)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.cpp)
