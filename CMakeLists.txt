cmake_minimum_required(VERSION 3.27)
project(Spoti_fam)

set(CMAKE_CXX_STANDARD 14)

add_executable(Spoti_fam
        Quiz.cpp
        Quiz.h
        Login.cpp
        Login.h
        Result.cpp
        Result.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include/SFML)
target_link_libraries(Spoti_fam sfml-system sfml-window sfml-graphics sfml-audio)