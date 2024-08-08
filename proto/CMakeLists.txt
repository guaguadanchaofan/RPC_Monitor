# # 查找 Protocol Buffers 库
# find_package(Protobuf REQUIRED)

# # 设置 .proto 文件
# set(PROTO_FILES monitor_info.proto
#                 cpu_load.proto
#                 cpu_softirq.proto
#                 cpu_stat.proto
#                 mem_info.proto
#                 net_info.proto
# )

# # 生成 C++ 文件
# protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

# # 添加静态库
# add_library(proto_lib STATIC ${PROTO_SRCS} ${PROTO_HDRS})

# # 链接 Protocol Buffers 库到 proto_lib
# target_link_libraries(proto_lib PRIVATE ${Protobuf_LIBRARIES})

# # 添加头文件目录
# target_include_directories(proto_lib PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
#cmake_minimum_required(VERSION 3.27.4)
project(ProtoLib)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加源文件
set(PROTO_FILES
    cpu_load.pb.cc
    cpu_softirq.pb.cc
    cpu_stat.pb.cc
    mem_info.pb.cc
    monitor_info.pb.cc
    net_info.pb.cc
)

# 添加库
add_library(proto_lib  ${PROTO_FILES})

# 添加Protobuf依赖
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
target_link_libraries(proto_lib ${PROTOBUF_LIBRARIES})