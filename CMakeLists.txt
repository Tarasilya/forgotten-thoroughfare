cmake_minimum_required(VERSION 3.10)
project(forgotten-thoroughfare)

if (APPLE)
set(LINKER_FLAGS "-framework sfml-system -framework sfml-window -framework sfml-graphics -framework sfml-network")
endif()

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_FLAGS}")

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++17" )

file(GLOB A "src/*/*.cpp")
file(GLOB B "src/*/*/*.cpp")
file(GLOB C "src/*/*/*/*.cpp")

set(SOURCES ${A} ${B} ${C})
file(GLOB SERVER "server/server.cpp")


add_executable(ft ${SOURCES}) 
target_include_directories(ft PRIVATE src)

add_executable(ser ${SERVER}) 

if (UNIX AND NOT APPLE) 
target_link_libraries(ft -L/usr/local/lib)
target_link_libraries(ft -lsfml-window)
target_link_libraries(ft -lsfml-system)
target_link_libraries(ft -lsfml-graphics)
target_link_libraries(ft -lsfml-network)
endif()
