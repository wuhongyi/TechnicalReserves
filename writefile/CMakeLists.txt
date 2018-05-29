#CMakeLists.txt --- 
# 
# Description: CMake编译、运行程序模板。
# Author: Hongyi Wu(吴鸿毅)
# Email: wuhongyi@qq.com 
# Created: 六 2月 22 19:39:08 2014 (+0800)
# Last-Updated: 三 4月 27 13:16:29 2016 (+0800)
#           By: Hongyi Wu(吴鸿毅)
#     Update #: 81
# URL: http://wuhongyi.cn 

#----------------------------------------------------------------------------
#判断cmake版本是否符合，对工程命名
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
set(CODE_DIR /home/wuhongyi/CodeProject )   #设置工程文件路径
#set(CMAKE_C_COMPILER "/usr/local/bin/gcc")  #调用自己安装在local的gcc
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++") #调用自己安装在local的g++
enable_language(Fortran)
set(PROJ_NAME wu)
project(${PROJ_NAME})
set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated") #支持最新c++11
#c++0x是新的C++意思。而-Wno-deprecated是表示 no-deprecated这类警告忽略。
SET(CMAKE_BUILD_TYPE Debug) #编译调试版本

#----------------------------------------------------------------------------
#add_executable()后面的是一个参数列表，可带多个要编译的文件名，中间以空格或回车等隔开。生成一个可执行文件
add_executable(${PROJ_NAME} main.cc global.hh User.hh User.cc) 
#链接库，后面补上名称
#target_link_libraries(${PROJ_NAME} )

#----------------------------------------------------------------------------


###################################
