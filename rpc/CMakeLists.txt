# RPC 框架的 CMake 配置

# 查找并包含 protobuf
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})

# 添加源文件
file(GLOB_RECURSE RPC_SOURCES "*.cc")
file(GLOB_RECURSE RPC_HEADERS "*.h")

# 创建 RPC 库
add_library(mprpc STATIC ${RPC_SOURCES} ${PROTO_SRCS})

# 链接库到目标
target_link_libraries(mprpc ${Protobuf_LIBRARIES})