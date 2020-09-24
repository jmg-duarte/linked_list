cmake_minimum_required(VERSION 3.10)
project(linked_list C)

set(CMAKE_C_STANDARD 11)

add_executable(linked_list main.c linked_list.c linked_list.h)
add_executable(linked_list_test tests.c linked_list.c linked_list.h tests.c linked_list_tests.c linked_list_tests.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(linked_list PRIVATE Threads::Threads)