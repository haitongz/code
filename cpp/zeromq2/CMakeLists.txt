project(demo)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(zmq_path "/usr/local/Cellar/zeromq/4.0.5_2")
include_directories("${zmq_path}/include")
link_directories("${zmq_path}/lib")

add_executable(puller2 puller2.cpp)
target_link_libraries(puller2 zmq pthread)

add_executable(pusher2 pusher2.cpp)
target_link_libraries(pusher2 zmq pthread)
