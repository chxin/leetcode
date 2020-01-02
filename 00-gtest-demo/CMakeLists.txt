cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/local/include)
project(demo)

find_package(GTEST REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
