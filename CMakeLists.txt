cmake_minimum_required(VERSION 3.27.4)#设置camke最低版本和项目名称
project(LinuxMontior)
# #生成debug版本进行gdb调试
# set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_CXX_STANDARD 17)

# #设置项目可执行文件的输出路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# #设置项目库文件输出路径
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# #设置项目编译头文件搜索路径
# include_directories(${PROJECT_SOURCE_DIR}/src/include/monitor)
# include_directories(${PROJECT_SOURCE_DIR}/src/include/rpc)
# include_directories(${PROJECT_SOURCE_DIR}/rpc_manager/)
# #include_directories(${PROJECT_SOURCE_DIR}/proto)
# #include_directories(${PROJECT_SOURCE_DIR}/example)
# #设置项目库文件搜索路径
# link_directories(${PROJECT_SOURCE_DIR}/lib)



# # #src包含了mprpc框架所有的相关代码
# add_subdirectory(exmample)
# # #example包含了mprpc框架使用的示例代码
# add_subdirectory(rpc)
# 设置库文件输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# 设置可执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 添加子目录
add_subdirectory(rpc)
add_subdirectory(example)