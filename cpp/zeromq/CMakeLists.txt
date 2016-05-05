project(demo)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_VERBOSE_MAKEFILE ON)
 
set(zmq_path "/usr/local/Cellar/zeromq/4.0.5_2")
include_directories("${zmq_path}/include")
link_directories("${zmq_path}/lib")
 
add_executable(puller puller.cpp)
target_link_libraries(puller zmq pthread)
 
add_executable(pusher pusher.cpp)
target_link_libraries(pusher zmq pthread)
