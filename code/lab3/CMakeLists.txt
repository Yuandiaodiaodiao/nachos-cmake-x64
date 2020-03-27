include(${CMAKE_HOME_DIRECTORY}/threads/threads_core.cmake)
FILE(GLOB_RECURSE lab3CPP
        main.cc
        prodcons++.cc
        ring.cc
        )

include_directories(
        .
)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(lab3_nachos ${lab3CPP} ${threadsCPP})