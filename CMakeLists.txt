cmake_minimum_required(VERSION 3.22)
project(engine)

set(CMAKE_CXX_STANDARD 20)

add_library(engine "")

add_subdirectory(vendor)
add_subdirectory(src)


add_subdirectory(sandbox)
