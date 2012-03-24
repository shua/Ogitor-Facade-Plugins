
project(PlayerPlugin)

set(HEADER_FILES
        FaPlayer.h
)

set(SOURCE_FILES
        FaPlayer.cpp
)

include_directories(${OGITOR_INCLUDE_DIRS})
include_directories(.)

add_library(PlayerPlugin SHARED ${HEADER_FILES} ${SOURCE_FILES})

set(LIBRARY_OUTPUT_PATH ${PLUGINS_OUTPUT_DIR})

set_target_properties(PlayerPlugin PROPERTIES COMPILE_DEFINITIONS PLUGIN_EXPORT)
set_target_properties(PlayerPlugin PROPERTIES SOLUTION_FOLDER Plugins)
