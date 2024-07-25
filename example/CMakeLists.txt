set(SRC_LIST online.cc)
# 为GCC和Clang添加-fPIC选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
add_executable(consumer ${SRC_LIST})
target_link_libraries(consumer proto_lib mprpc protobuf)