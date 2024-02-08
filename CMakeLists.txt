cmake_minimum_required(VERSION 3.28.1)

set(PROJECT_NAME "crypto_app")
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${nlohmann_json_INCLUDE_DIRS})

project(${PROJECT_NAME} LANGUAGES CXX)
add_subdirectory(api)
add_subdirectory(third_party)



add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} api)
  


