cmake_minimum_required(VERSION 3.12)
project(oop_exercise_08)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(oop_exercise_08 main.cpp point.cpp five_angles.cpp six_angles.cpp eight_angles.cpp)

target_link_libraries(oop_exercise_08 Threads::Threads)
