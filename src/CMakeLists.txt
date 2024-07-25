cmake_minimum_required(VERSION 3.27.4)
project(Monitor)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加源文件
set(SOURCE_FILES
    cpu_load.cc
    cpu_softirq.cc
    cpu_stat.cc
    read_file.cc
)

# 添加库
add_library(monitor ${SOURCE_FILES})

