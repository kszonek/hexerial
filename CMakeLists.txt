cmake_minimum_required(VERSION 2.8.9)

project(hexerial)

include_directories(include)

add_executable(hexerial
    src/main.cpp
    src/config.cpp
    src/hexerial.cpp
    include/config.hpp
    include/hexerial.hpp
    include/version.hpp
)
