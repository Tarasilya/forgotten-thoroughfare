cmake_minimum_required(VERSION 3.10)
project(forgotten-thoroughfare)

if (APPLE)
set(LINKER_FLAGS "-framework sfml-system -framework sfml-window -framework sfml-graphics")
endif()

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_FLAGS}")

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11" )

file(GLOB A "*/*.cpp")
file(GLOB B "*/items/*.cpp")
file(GLOB C "*/items/stick/*.cpp")
file(GLOB D "*/player/*.cpp")

set(SOURCES ${A} ${B} ${C} ${D})


add_executable(ft ${SOURCES}) 
target_include_directories(ft PRIVATE .)

if (UNIX AND NOT APPLE) 
target_link_libraries(ft -L/usr/local/lib)
target_link_libraries(ft -lsfml-window)
target_link_libraries(ft -lsfml-system)
target_link_libraries(ft -lsfml-graphics)
endif()
