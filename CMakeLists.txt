# cmake最低版本号要求
cmake_minimum_required (VERSION 3.0)
# # 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# # 指定为C++03 版本
# set(CMAKE_CXX_STANDARD 03)

# 设置gdb为调试工具
# 构建模式设置为Debug
SET(CMAKE_BUILD_TYPE "Debug")
# 调试时使用gdb
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
# 发布时使用优化(1~3)
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 获取当前文件夹名称
string(REGEX REPLACE ".*/\(.*\)" "\\1" CURDIR ${CMAKE_CURRENT_SOURCE_DIR})
# 设置PROJECT_NAME变量
set(PROJECT_NAME ${CURDIR})
# 设置工程名
project (${PROJECT_NAME})
# 查找当前目录下的所有源文件并存入DIR_SRCS变量
aux_source_directory(src DIR_SRCS)
# 添加一个可编译的目标到工程
add_executable (${PROJECT_NAME} ${DIR_SRCS})
# 添加静态库, 必须写在add_executable之后
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
message("PROJECT_NAME: ${PROJECT_NAME}")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")