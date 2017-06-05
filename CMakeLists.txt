cmake_minimum_required(VERSION 3.7)
project(NewSockets)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES_S main.cpp server.cpp )
set(SOURCE_FILES_C client.cpp)

add_executable(server ${SOURCE_FILES_S})
add_executable(client ${SOURCE_FILES_C})
