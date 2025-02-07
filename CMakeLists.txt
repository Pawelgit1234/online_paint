cmake_minimum_required(VERSION 3.15...3.31)

project(OnlinePaint LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS log log_setup unit_test_framework)

if(Boost_FOUND)
    message(STATUS "Boost found: ${Boost_INCLUDE_DIRS}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

file (GLOB MAIN_SOURCES "src/*/*.cpp")
file (GLOB MAIN_HEADERS "src/*/*.hpp")
file (GLOB OTHER_SOURCES "src/*/*/*.cpp")
file (GLOB OTHER_HEADERS "src/*/*/*.hpp")

add_executable(online_paint.exe
               src/main.cpp
               src/settings.hpp
               ${MAIN_SOURCES}
               ${MAIN_HEADERS}
               ${OTHER_SOURCES}
               ${OTHER_HEADERS}
               )

target_link_libraries(online_paint.exe Boost::log Boost::log_setup)


file (GLOB TEST_SOURCES "tests/*.cpp")

add_executable(tests.exe
               src/settings.hpp
               ${TEST_SOURCES}
               ${MAIN_SOURCES}
               ${MAIN_HEADERS}
               ${OTHER_SOURCES}
               ${OTHER_HEADERS}
               )

target_link_libraries(tests.exe Boost::unit_test_framework)