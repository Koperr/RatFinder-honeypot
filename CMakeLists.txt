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

# System-specific configurations
if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin") # macOS
    message(STATUS "Configuring for macOS")
    target_include_directories(RatFinder PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/libhttpserver/src
        /opt/homebrew/include)
    link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/libhttpserver/lib
        /opt/homebrew/lib)
    target_link_libraries(RatFinder 
        /opt/homebrew/lib/libhttpserver.a 
        /System/Volumes/Data/opt/homebrew/lib/libmicrohttpd.a 
        PcapPlusPlus::Pcap++)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux") # Linux
    message(STATUS "Configuring for Linux")
    target_include_directories(RatFinder PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/libhttpserver/src
        /usr/local/include)
    link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/libhttpserver/lib
        /usr/local/lib)
    target_link_libraries(RatFinder 
        /usr/lib/x86_64-linux-gnu/libmicrohttpd.a
        /usr/local/lib/libhttpserver.a
        PcapPlusPlus::Pcap++)
else()
    message(FATAL_ERROR "Unsupported system: ${CMAKE_SYSTEM_NAME}")
endif()

find_package(PcapPlusPlus REQUIRED)


target_link_libraries(RatFinder
    PcapPlusPlus::Pcap++)


# includes files /inc
target_include_directories(RatFinder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

