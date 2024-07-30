cmake_minimum_required(VERSION 3.27.4)#设置camke最低版本和项目名称
project(LinuxMonitor)
# #生成debug版本进行gdb调试
# set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_CXX_STANDARD 17)
# #设置项目可执行文件的输出路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# #设置项目库文件输出路径
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# #设置项目编译头文件搜索路径
# include_directories(${PROJECT_SOURCE_DIR}/include/rpc)
# include_directories(${PROJECT_SOURCE_DIR}/proto)
# include_directories(${PROJECT_SOURCE_DIR}/include/monitor)
# #设置项目库文件搜索路径
# link_directories(${PROJECT_SOURCE_DIR}/lib)

# #src包含了mprpc框架所有的相关代码
# add_subdirectory(src)
# add_subdirectory(rpc)
# #example包含了mprpc框架使用的示例代码
# add_subdirectory(example)
# add_subdirectory(proto)
# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE "Debug")

# include_directories(${CMAKE_SOURCE_DIR}/include)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/include/rpc)
include_directories(${PROJECT_SOURCE_DIR}/include/mysql)
include_directories(${PROJECT_SOURCE_DIR}/proto)
include_directories(${PROJECT_SOURCE_DIR}/include/monitor)
# 添加子目录
add_subdirectory(src)
add_subdirectory(proto)
add_subdirectory(rpc)
add_subdirectory(example)

# 确保位置无关代码（PIC）
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")