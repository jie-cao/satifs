cmake_minimum_required(VERSION 3.16)
project(satifs)

set(CMAKE_CXX_STANDARD 14)

add_executable(satifs main.cpp main.cpp server/namenode/inode.cpp server/namenode/inode.h)