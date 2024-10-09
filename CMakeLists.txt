cmake_minimum_required(VERSION 3.10)

project(picola VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_compile_options(-g -fdiagnostics-color=always)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SOURCES)
add_library(picola ${SOURCES})

target_include_directories(picola PUBLIC ${CMAKE_SOURCE_DIR}/include)
