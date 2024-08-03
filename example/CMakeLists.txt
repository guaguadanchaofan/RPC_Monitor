# set(SRC_LIST online.cc)
# # 为GCC和Clang添加-fPIC选项
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
# add_executable(consumer ${SRC_LIST})
# target_link_libraries(consumer proto_lib mprpc protobuf)
cmake_minimum_required(VERSION 3.27.4)
project(Example)
# 添加源文件
set(SOURCE_FILES
    # client.cc
    # server.cc
    online.cc
)
set(SERVER_FILE server.cc)
set(CILENT_FILE client.cc)

# 添加可执行文件
add_executable(online ${SOURCE_FILES})
add_executable(server ${SERVER_FILE})
add_executable(client ${CILENT_FILE})



# 链接库

target_link_libraries(online  monitor mysqlclient boost_system boost_chrono proto_lib mprpc zookeeper_mt)
target_link_libraries(server  monitor mysqlclient boost_system boost_chrono proto_lib mprpc zookeeper_mt)
target_link_libraries(client  monitor mysqlclient boost_system boost_chrono proto_lib mprpc zookeeper_mt)