cmake_minimum_required(VERSION 3.26)
project(Szachy_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Szachy_cpp main.cpp
        Chessboard.cpp
        headers/Chessboard.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Szachy_cpp sfml-system sfml-window sfml-graphics sfml-audio)
