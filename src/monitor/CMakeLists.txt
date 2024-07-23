aux_source_directory(. SRC_LIST)#当前目录下所有源文件
add_library(monitor ${SRC_LIST})#生成动态库
target_link_libraries(monitor)