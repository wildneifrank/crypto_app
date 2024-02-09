cmake_minimum_required(VERSION 3.28.1)

# Set the project name
set(PROJECT_NAME "api")
project(${PROJECT_NAME} LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add the source files
set(SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/encryption.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/http_server.cpp"
)

# Add the header files
set(HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/encryption.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/http_server.h"
)

# Add the library
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} httplib nlohmann_json)
