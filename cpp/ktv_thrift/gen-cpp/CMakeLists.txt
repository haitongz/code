PROJECT (client)
SET (SRC_LIST KeyWordsToVector.cpp query_constants.cpp query_types.cpp client.cpp )
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
SET (CMAKE_CXX_COMPILER "clang++")
#SET (CMAKE_CXX_FLAGS "-O -g -w -Wall -std=c++11 -stdlib=libc++ -v") -verbose
SET (CMAKE_CXX_FLAGS "-O -g -w -Wall -std=c++11 -stdlib=libc++")
MESSAGE (STATUS "This is BINARY dir" ${client_BINARY_DIR})
MESSAGE (STATUS "This is SOURCE dir" ${client_SOURCE_DIR})
#非标准的头文件搜索路径
INCLUDE_DIRECTORIES (/usr/local/Cellar/thrift/0.9.2/include)
#非标准库文件搜索路径
LINK_DIRECTORIES(/usr/local/Cellar/thrift/0.9.2/lib)
ADD_EXECUTABLE (client ${SRC_LIST})
TARGET_LINK_LIBRARIES(client libthriftnb.a libthrift.a)
#aux_source_directory 命令，该命令会查找指定目录下的所有源文件，然后将结果存进指定变量名
