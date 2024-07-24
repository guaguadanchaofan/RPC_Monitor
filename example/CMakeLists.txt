# 示例代码的 CMake 配置

# 添加示例源文件
file(GLOB SOURCES "*.cpp")

# 创建示例程序
add_executable(server server.cc)
add_executable(client client.cc)

# 链接 RPC 库到示例程序
target_link_libraries(server mprpc)
target_link_libraries(client mprpc)