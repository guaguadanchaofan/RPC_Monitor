# Proto 文件的 CMake 配置

# 生成 C++ 源文件和头文件
file(GLOB PROTO_FILES "*.proto")
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

# 将生成的文件添加到项目中
include_directories(${CMAKE_CURRENT_BINARY_DIR})