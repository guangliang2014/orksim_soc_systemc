cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(Learn_ESL)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



include_directories(
    /usr/include
    /usr/include/sysc
    /home/ut/systemc/or1ksim/or1k/include
)

link_directories(
    /usr/lib/x86_64-linux-gnu/lib64
    /home/ut/systemc/or1ksim/or1k/lib
)


add_subdirectory(logger)
add_subdirectory(simple-soc)
add_subdirectory(sync-soc)
add_subdirectory(intr-soc)