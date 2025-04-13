cmake_minimum_required(VERSION 3.10)

# Define the project
project(CircularBuffer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directory
include_directories(include)

# Add the executable
add_executable(circular_buffer 
                src/main.cpp
                src/CircularBuffer.cpp)
