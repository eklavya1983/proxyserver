cmake_minimum_required(VERSION 2.8)
project("httpserver")

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# External dependency include directories
include_directories(/home/nbayyana/temp/proxyserver/3rdparty/proxygen /home/nbayyana/temp/proxyserver/3rdparty/proxygen/proxygen/fbthrift/thrift/folly)

# External dependency library directories
LINK_DIRECTORIES(/home/nbayyana/temp/proxyserver/3rdparty/proxygen/proxygen/fbthrift/thrift/folly/folly/.libs /home/nbayyana/temp/proxyserver/3rdparty/proxygen/proxygen/httpserver/.libs)

# Executable
add_executable(httpserver TestHttpServer.cpp TestHttpHandler.cpp)

# Exteranl dependency libs
TARGET_LINK_LIBRARIES(httpserver proxygenhttpserver folly glog gflags pthread)
