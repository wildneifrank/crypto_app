cmake_minimum_required(VERSION 3.28.1)

set(PROJECT_NAME "api")
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_library(api STATIC "${CMAKE_CURRENT_SOURCE_DIR}/src/encryption.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/include/encryption.h")