
project(SoundPlugin)

set(HEADER_FILES
        FaSound.h
)

set(SOURCE_FILES
        FaSound.cpp
)

include_directories(${OGITOR_INCLUDE_DIRS})
include_directories(.)

add_library(SoundPlugin SHARED ${HEADER_FILES} ${SOURCE_FILES})

set(LIBRARY_OUTPUT_PATH ${PLUGINS_OUTPUT_DIR})

set_target_properties(SoundPlugin PROPERTIES COMPILE_DEFINITIONS PLUGIN_EXPORT)
set_target_properties(SoundPlugin PROPERTIES SOLUTION_FOLDER Plugins)