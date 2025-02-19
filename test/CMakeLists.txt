cmake_minimum_required(VERSION 3.10)

project(Catch2Tests LANGUAGES CXX)

# Find Catch2
find_package(Catch2 CONFIG REQUIRED)

# Collect test source files
file(GLOB_RECURSE TEST_SRC_FILES "${CMAKE_SOURCE_DIR}/test/*.cpp")

# Create the test executable
add_executable(unit_test ${TEST_SRC_FILES})

# Link the benchmark_lib and Catch2 to the test executable
target_link_libraries(unit_test PRIVATE benchmark_lib Catch2::Catch2WithMain)

# Add the include directory for unit_test
target_include_directories(unit_test PRIVATE "${CMAKE_SOURCE_DIR}")

target_compile_options(unit_test PRIVATE -O2)
