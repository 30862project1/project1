cmake_minimum_required(VERSION 2.8.4)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1
        interpreter_input.smp
        main.cpp MemoryObject.cpp MemoryObject.h Memory.cpp Memory.h RunStack.cpp RunStack.h FrameStack.cpp FrameStack.h)
