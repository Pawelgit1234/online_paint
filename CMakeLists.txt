cmake_minimum_required(VERSION 3.15...3.31)

project(OnlinePaint LANGUAGES CXX)

file (GLOB PAINT_SOURCES "src/*/*.cpp")
file (GLOB PAINT_HEADERS "src/*/*.hpp")
file (GLOB OTHER_SOURCES "src/paint/*/*.cpp")
file (GLOB OTHER_HEADERS "src/paint/*/*.hpp")

add_executable(online_paint.exe
               src/main.cpp
               src/settings.hpp
               src/settings.cpp
               ${PAINT_SOURCES}
               ${PAINT_HEADERS}
               ${OTHER_SOURCES}
               ${OTHER_HEADERS}
               )