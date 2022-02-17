cmake_minimum_required(VERSION 3.20)
project(HeadsHandsTask)

set(CMAKE_CXX_STANDARD 14)

add_executable(HeadsHandsTask main.cpp MergeSorter.h NumberGenerator.h NumberGenerator.cpp ArrayGenerator.cpp ArrayGenerator.h IGenerator.h Exceptions/BaseException.h Exceptions/MemoryNotAllocatedException.h Array.h Exceptions/InvalidArgumentException.h)