cmake_minimum_required(VERSION 3.30)
project(NIN)

set(NIN_MAIN "nin.cpp")
set(NIN_INCLUDE "../include")
aux_source_directory("." NIN_SOURCES)
add_library(nin SHARED ${NIN_MAIN} ${NIN_SOURCES})
target_include_directories(nin PUBLIC "../include")
