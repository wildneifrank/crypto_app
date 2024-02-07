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
    "${CMAKE_CURRENT_SOURCE_DIR}/include/httplib.h"  # Assuming httplib.h is in the include directory
)

# Add the library
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

# Include directories for the target
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
