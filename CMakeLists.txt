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
file (GLOB OTHER_SOURCES "src/*/*/*.cpp")
file (GLOB TEST_SOURCES "tests/*.cpp")

# Client
add_executable(online_paint_client.exe
               src/client_main.cpp
               src/settings.hpp
               ${MAIN_SOURCES}
               ${OTHER_SOURCES}
               )

target_link_libraries(online_paint_client.exe)

# Server
add_executable(online_paint_server.exe
               src/server_main.cpp
               src/settings.hpp
               ${MAIN_SOURCES}
               ${OTHER_SOURCES}
               )

target_link_libraries(online_paint_server.exe Boost::log Boost::log_setup)

# Tests
add_executable(tests.exe
               src/settings.hpp
               ${TEST_SOURCES}
               ${MAIN_SOURCES}
               ${OTHER_SOURCES}
               )

target_link_libraries(tests.exe Boost::unit_test_framework)