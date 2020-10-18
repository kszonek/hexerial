cmake_minimum_required(VERSION 2.8.9)

project(hexerial)

include_directories(include)

add_executable(hexerial
    src/main.cpp
    src/hexerial.cpp
    include/hexerial.hpp
    include/version.hpp
)
