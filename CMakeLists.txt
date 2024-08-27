cmake_minimum_required(VERSION 3.15)
project(RatFinder)

# build type (Debug/Release)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CSS_FLAGS} -Wall -Werror -std=c++17")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (project_dir "${CMAKE_CURRENT_SOURCE_DIR}/")
file (GLOB source_files "${source_dir}/*.cpp")


# defines output directories
set (FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")


add_executable(RatFinder ${source_files})

link_directories(/opt/homebrew/lib)

target_include_directories(RatFinder PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/libhttpserver/src
    /opt/homebrew/include)

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/libhttpserver/lib
    /opt/homebrew/lib)

find_package(PcapPlusPlus REQUIRED)


target_link_libraries(RatFinder /opt/homebrew/lib/libhttpserver.a 
    /System/Volumes/Data/opt/homebrew/lib/libmicrohttpd.a 
    PcapPlusPlus::Pcap++)


# includes files /inc
target_include_directories(RatFinder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

