cmake_minimum_required(VERSION 3.20)
project(my-malloc)
set(CMAKE_C_STANDARD 99)

#add dyn-alloc.c file of the project root directory as a source file
set(SOURCE_FILES dyn-alloc.c)

# add executable target with source files listed in SOURCE_FILES varable
add_executable(my-malloc ${SOURCE_FILES})