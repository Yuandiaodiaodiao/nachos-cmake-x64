FILE(GLOB_RECURSE assCPP
        main.cc
        prodcons++.cc
        ring.cc

        ${CMAKE_HOME_DIRECTORY}/*/list.cc
        ${CMAKE_HOME_DIRECTORY}/*/scheduler.cc
        ${CMAKE_HOME_DIRECTORY}/threads/synch.cc
        ${CMAKE_HOME_DIRECTORY}/*/synchlist.cc
        ${CMAKE_HOME_DIRECTORY}/*/system.cc
        ${CMAKE_HOME_DIRECTORY}/*/thread.cc
        ${CMAKE_HOME_DIRECTORY}/*/utility.cc
        ${CMAKE_HOME_DIRECTORY}/*/threadtest.cc
        ${CMAKE_HOME_DIRECTORY}/*/synchtest.cc
        ${CMAKE_HOME_DIRECTORY}/*/interrupt.cc
        ${CMAKE_HOME_DIRECTORY}/*/sysdep.cc
        ${CMAKE_HOME_DIRECTORY}/*/stats.cc
        ${CMAKE_HOME_DIRECTORY}/*/timer.cc
        ${CMAKE_HOME_DIRECTORY}/*/switch.s
        )
include_directories(
        ${CMAKE_HOME_DIRECTORY}/ass3
        ${CMAKE_HOME_DIRECTORY}/threads
        ${CMAKE_HOME_DIRECTORY}/machine
)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DTHREADS)
add_executable(ass3_nachos ${assCPP})