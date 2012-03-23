
project(PhysicsPlugin)

set(HEADER_FILES
        Fysics.h
)

set(SOURCE_FILES
        Fysics.cpp
)

include_directories(${OGITOR_INCLUDE_DIRS})
include_directories(.)

add_library(PhysicsPlugin SHARED ${HEADER_FILES} ${SOURCE_FILES})

set(LIBRARY_OUTPUT_PATH ../lib)

set_target_properties(PhysicsPlugin PROPERTIES COMPILE_DEFINITIONS PLUGIN_EXPORT)
set_target_properties(PhysicsPlugin PROPERTIES SOLUTION_FOLDER Plugins)
