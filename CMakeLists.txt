cmake_minimum_required(VERSION 3.16)
project(satifs)

set(CMAKE_CXX_STANDARD 14)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(satifs main.cpp main.cpp src/server/namenode/inode.cpp src/server/namenode/inode.h src/server/namenode/inode_attributes.cpp
        src/server/namenode/inode_attributes.h src/server/namenode/inode_file.h src/server/namenode/inode_file.cpp src/server/namenode/inode_directory.h
        src/server/namenode/inode_directory.cpp src/server/block_management/block_info.cpp src/server/block_management/block_info.h src/server/block_management/datanode_storage_info.cpp src/server/block_management/datanode_storage_info.h)