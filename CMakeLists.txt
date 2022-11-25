cmake_minimum_required(VERSION 3.23)
project(raytracing)

set(CMAKE_CXX_STANDARD 23)

add_executable(raytracing main.cpp vec3.h ray.h hitable.h sphere.h hitablelist.h)
