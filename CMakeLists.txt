cmake_minimum_required(VERSION 3.19)
project(Reflection)

set(CMAKE_CXX_STANDARD 17)

add_executable(Reflection main.cpp reflection/reflection.cpp reflection/reflection.h core/Vector3.cpp core/Vector3.h gen/vector3_gen.h gen/vectorValue.h)
