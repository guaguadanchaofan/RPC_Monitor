# example/CMakeLists.txt

# 添加可执行文件
add_executable(server
    server.cpp
    # 其他源文件
)

add_executable(client
    client.cpp
    # 其他源文件
)

# 链接库到可执行文件
target_link_libraries(server mprpc)
target_link_libraries(client mprpc)

# 设置可执行文件输出路径
set_target_properties(server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

set_target_properties(client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)