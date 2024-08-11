project(msqlpool)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加源文件
set(SOURCE_FILES
    mysqlconn.cc
    ConnectionPool.cc
)

# 添加库
add_library(mysql ${SOURCE_FILES})


