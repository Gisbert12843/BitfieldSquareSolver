cmake_minimum_required(VERSION 3.10)

project(MainProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Set the prefix path for vcpkg
# if(NOT CMAKE_PREFIX_PATH)
#     set(CMAKE_PREFIX_PATH "C:/DevTools/vcpkg/installed/x64-mingw-static" CACHE INTERNAL "")
# endif()

# Collect source files (excluding main.cpp for the library)
file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
list(REMOVE_ITEM SRC_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Create a library for shared code
add_library(benchmark_lib ${SRC_FILES})

include_directories("${CMAKE_SOURCE_DIR}")
list(REMOVE_ITEM SRC_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

if(NOT CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH "C:/DevTools/vcpkg/installed/x64-mingw-static" CACHE INTERNAL "")
endif() 
# Create the main executable
add_executable(main "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Link the library to the main executable
target_link_libraries(main PRIVATE benchmark_lib)

# Set compiler options
target_compile_options(main PRIVATE -O2)
target_compile_options(benchmark_lib PRIVATE -O2)

# Find and link Catch2 (if needed)
find_package(Catch2 CONFIG REQUIRED)

# Enable testing and add test directory
enable_testing()
add_test(NAME unit_test COMMAND unit_test)
add_subdirectory(test)