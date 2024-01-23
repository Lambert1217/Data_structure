cmake_minimum_required(VERSION 3.26)

set(CXX_STANDARD_REQUIRED on)
set(CXX_STANDARD 11)

project(data_structure LANGUAGES CXX)

# 设置输出路径
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)  # 静态库
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)  # 可执行文件
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)  # 动态库

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/myList)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/myStack)