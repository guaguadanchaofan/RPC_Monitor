# aux_source_directory(. SRC_LIST)#当前目录下所有源文件
# add_library(mprpc ${SRC_LIST})#生成静态态库
# target_link_libraries(mprpc muduo_net muduo_base pthread)
#cmake_minimum_required(VERSION 3.27.4)

project(MPRPC)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加源文件
set(SOURCE_FILES
    logger.cc
    mprpcapplication.cc
    mprpcchannel.cc
    mprpcconfig.cc
    mprpcontrller.cc
    rpcheader.pb.cc
    rpcprovider.cc
    zookeeperutil.cc
)

# 添加库
add_library(mprpc  ${SOURCE_FILES})

# 添加Protobuf依赖
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
target_link_libraries(mprpc muduo_net muduo_base pthread ${PROTOBUF_LIBRARIES})