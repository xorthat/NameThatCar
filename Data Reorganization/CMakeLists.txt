cmake_minimum_required(VERSION 3.3)
project(Data_Reorganization)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(Data_Reorganization ${SOURCE_FILES})
file(COPY ${CMAKE_SOURCE_DIR}/resources/train_perfect_preds_org.txt DESTINATION ${CMAKE_BINARY_DIR})