cmake_minimum_required(VERSION 4.0)
project("Old Faithful fstream Examples")

set(CMAKE_CXX_STANDARD 20)

add_executable(old_faithful_part1
        main.cpp
        src/data_processor.hpp)
