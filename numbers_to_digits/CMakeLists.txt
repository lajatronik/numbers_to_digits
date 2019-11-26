cmake_minimum_required(VERSION 2.6)
project(numbers_to_digits)

add_executable(numbers_to_digits main.cpp)

install(TARGETS numbers_to_digits RUNTIME DESTINATION bin)
