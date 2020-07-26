cmake_minimum_required(VERSION 3.16)
project(satifs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/../library/include)
set(CMAKE_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/../library/lib)
set(INC_DIR ${PROJECT_SOURCE_DIR}/../library/include)
set(LINK_DIR ${PROJECT_SOURCE_DIR}/../library/lib)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS src/proto/echo.proto)
protobuf_generate_cpp(COUNTER_PROTO_SRCS COUNTER_PROTO_HDRS src/proto/counter.proto)

find_path(BRPC_INCLUDE_PATH NAMES brpc/server.h)
find_library(BRPC_LIB NAMES library/lib/libbrpc.a brpc)

find_library(ROCKSDB_LIB NAMES librocksdb.a PATHS ${LINK_DIR} NO_DEFAULT_PATH)
find_library(Z_LIB NAMES libz.a PATHS ${LINK_DIR} NO_DEFAULT_PATH)
find_library(SNAPPY_LIB NAMES libsnappy.a PATHS ${LINK_DIR} NO_DEFAULT_PATH)
find_library(LIBZIP_LIB NAMES libzip.a PATHS ${LINK_DIR} NO_DEFAULT_PATH)
find_library(LZ4_LIB NAMES liblz4.a PATHS ${LINK_DIR} REQUIRED)
find_library(ZSTD_LIB NAMES libzstd.a PATHS ${LINK_DIR} REQUIRED)
find_library(BZ2_LIB NAMES libbz2.a PATHS ${LINK_DIR} REQUIRED)

find_library(SPDLOG_LIB NAMES libspdlog.a PATHS ${LINK_DIR} NO_DEFAULT_PATH)
if((NOT BRPC_INCLUDE_PATH) OR (NOT BRPC_LIB))
    message(FATAL_ERROR "Fail to find brpc")
endif()


SET(DYNAMIC_LIBS
        ${Z_LIB}
        ${SNAPPY_LIB}
        ${LIBZIP_LIB}
        ${LZ4_LIB}
        ${ZSTD_LIB}
        ${BZ2_LIB}
        ${SPDLOG_LIB}
        dl
        )
message(DYNAMIC_LIBS "=>${DYNAMIC_LIBS}")
message(ROCKSDB_LIB "=>${ROCKSDB_LIB}")
include_directories(${BRPC_INCLUDE_PATH})
include_directories(${PROJECT_SOURCE_DIR}/src)

link_directories(${LINK_DIR})

add_executable(satifs main.cpp src/server/namenode/inode.cpp src/server/namenode/inode.h src/server/namenode/inode_attributes.cpp
        src/server/namenode/inode_attributes.h src/server/namenode/inode_file.h src/server/namenode/inode_file.cpp src/server/namenode/inode_directory.h
        src/server/namenode/inode_directory.cpp src/server/block_management/block_info.cpp src/server/block_management/block_info.h
        src/server/block_management/datanode_storage_info.cpp src/server/block_management/datanode_storage_info.h
        ${PROTO_SRCS} ${PROTO_HDRS} ${COUNTER_PROTO_SRCS} ${COUNTER_PROTO_HDRS} src/server/ha/raft_service.cpp src/server/ha/raft_service.h src/test/inode_file_test.cpp)
target_link_libraries(satifs ${BRPC_LIB} ${Protobuf_LIBRARIES} ${ROCKSDB_LIB} ${DYNAMIC_LIBS})

add_executable(satifs_client src/client/client.cpp ${PROTO_SRCS} ${PROTO_HDRS} ${COUNTER_PROTO_SRCS} ${COUNTER_PROTO_HDRS})
target_link_libraries(satifs_client ${BRPC_LIB} ${Protobuf_LIBRARIES} ${SPDLOG_LIB})