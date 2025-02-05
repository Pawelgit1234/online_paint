cmake_minimum_required(VERSION 3.15...3.31)

project(OnlinePaint LANGUAGES CXX)

file (GLOB MAIN_SOURCES "src/*/*.cpp")
file (GLOB MAIN_HEADERS "src/*/*.hpp")
file (GLOB OTHER_SOURCES "src/paint/*/*.cpp")
file (GLOB OTHER_HEADERS "src/paint/*/*.hpp")

add_executable(online_paint.exe
               src/main.cpp
               src/settings.hpp
               ${MAIN_SOURCES}
               ${MAIN_HEADERS}
               ${OTHER_SOURCES}
               ${OTHER_HEADERS}
               )