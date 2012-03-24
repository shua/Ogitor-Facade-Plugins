project(ogitor-facade-plugins)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules/;${CMAKE_MODULE_PATH}")

find_package(OGRE REQUIRED)

if(NOT DEFINED OGITOR_INCLUDE_DIRS) 
    if(EXISTS "${PROJECT_SOURCE_DIR}/../Ogitor/include/")
        set(OGITOR_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/../Ogitor/include/")
    else()
        message(FATAL_ERROR "The directory ${PROJECT_SOURCE_DIR}/../Ogitor/include/ doesn't exist." 
                " Please set the directory containing the headers of Ogitor" 
                " with \" -D OGITOR_INCLUDE_DIRS=/absolute/path/to/include/dir/\"")
    endif()
endif()

if(NOT DEFINED PLUGINS_OUTPUT_DIR) 
    set(PLUGINS_OUTPUT_DIR "${PROJECT_SOURCE_DIR}/Libraries")
endif()

include_directories(${OGRE_INCLUDE_DIRS})
include_directories(${OGITOR_INCLUDE_DIRS})

add_subdirectory(Plugins)
# add_executable(ogitor-facade-plugins main.cpp)

