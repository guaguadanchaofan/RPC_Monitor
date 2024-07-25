# 查找 Protocol Buffers 库
find_package(Protobuf REQUIRED)

# 设置 .proto 文件
set(PROTO_FILES monitor_info.proto
                cpu_load.proto
                cpu_softirq.proto
                cpu_stat.proto
                mem_info.proto
                net_info.proto
)

# 生成 C++ 文件
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

# 添加静态库
add_library(proto_lib STATIC ${PROTO_SRCS} ${PROTO_HDRS})

# 链接 Protocol Buffers 库到 proto_lib
target_link_libraries(proto_lib PRIVATE ${Protobuf_LIBRARIES})

# 添加头文件目录
target_include_directories(proto_lib PUBLIC ${CMAKE_CURRENT_BINARY_DIR})