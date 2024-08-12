cmake_minimum_required(VERSION 3.15)
project(run)

# build type (Debug/Release)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CSS_FLAGS} -Wall -Werror -std=c++17")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
file (GLOB source_files "${source_dir}/*.cpp")


# defines output directories
set (FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")


# add_library(log SHARED "./src/log.cpp") 
# adds dynamic lib (compiles files to dynamic lib -> ".dll" on windows; ".so" on linux), needs to be specified

add_executable(run ${source_files})

# links header files from ./inc directory
target_include_directories(run PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

