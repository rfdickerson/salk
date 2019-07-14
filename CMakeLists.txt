
cmake_minimum_required(VERSION 3.12)

project(example)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(SDL2 REQUIRED)
find_package(DevIL REQUIRED)
find_package(GLEW 2.0 REQUIRED)
find_package(OpenGL REQUIRED)

project(hodhr)
subdirs(Hodhr)
