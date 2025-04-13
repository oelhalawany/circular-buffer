cmake_minimum_required(VERSION 3.10)
project(CircularBufferProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === Fetch GoogleTest ===
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# === CircularBuffer Library ===
add_library(CircularBuffer
    src/CircularBuffer.cpp
)

target_include_directories(CircularBuffer
    PUBLIC include
)

# === Main Executable ===
add_executable(CircularBufferApp
    src/main.cpp
)

target_link_libraries(CircularBufferApp
    PRIVATE CircularBuffer
)

# === Tests ===
enable_testing()

add_executable(runTests
    tests/CircularBufferTests.cpp
)

target_link_libraries(runTests
    PRIVATE
        CircularBuffer
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(runTests)
