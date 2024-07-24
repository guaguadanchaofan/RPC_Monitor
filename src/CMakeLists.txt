# 源代码的 CMake 配置

# 添加源文件
file(GLOB_RECURSE SRC_SOURCES "*.cc")
file(GLOB_RECURSE SRC_HEADERS "*.h")

# 创建监控功能库（如果需要）
add_library(monitor STATIC ${SRC_SOURCES})

# 链接 RPC 库到监控库
target_link_libraries(monitor mprpc)

# 添加主程序
add_executable(server main.cc)
add_executable(client main.cc)

# 链接库到可执行文件
target_link_libraries(server monitor)
target_link_libraries(client monitor)