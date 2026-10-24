cmake_minimum_required(VERSION 3.10)
project(thread_n_lock CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/app)
