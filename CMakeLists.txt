cmake_minimum_required(VERSION 3.20)
project(VideoStore)

set(CMAKE_CXX_STANDARD 14)

add_executable(VideoStore main.cpp Admin.cpp Admin.h Video.cpp Video.h Category.h)
