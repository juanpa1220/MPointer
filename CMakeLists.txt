cmake_minimum_required(VERSION 3.12)
project(MPointer)

set(CMAKE_CXX_STANDARD 11)
include_directories(. include/rapidjson)
add_executable(MPointer main.cpp src/client/MCliente.h src/client/MCliente.cpp src/client/JSONMakerClient.h src/client/JSONMakerClient.cpp)