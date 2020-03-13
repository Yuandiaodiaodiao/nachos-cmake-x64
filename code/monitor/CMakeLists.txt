FILE(GLOB_RECURSE monitorCPP
        main.cc
        synch.cc
        prodcons++.cc
        ring.cc

        ${CMAKE_HOME_DIRECTORY}/threads/switch.s
        ${CMAKE_HOME_DIRECTORY}/threads/list.cc
        ${CMAKE_HOME_DIRECTORY}/threads/scheduler.cc
        ${CMAKE_HOME_DIRECTORY}/threads/synchlist.cc
        ${CMAKE_HOME_DIRECTORY}/threads/system.cc
        ${CMAKE_HOME_DIRECTORY}/threads/thread.cc
        ${CMAKE_HOME_DIRECTORY}/threads/utility.cc
        ${CMAKE_HOME_DIRECTORY}/threads/threadtest.cc
        ${CMAKE_HOME_DIRECTORY}/threads/synchtest.cc
        ${CMAKE_HOME_DIRECTORY}/machine/interrupt.cc
        ${CMAKE_HOME_DIRECTORY}/machine/sysdep.cc
        ${CMAKE_HOME_DIRECTORY}/machine/stats.cc
        ${CMAKE_HOME_DIRECTORY}/machine/timer.cc
        )

include_directories(
        ${CMAKE_HOME_DIRECTORY}/monitor
        ${CMAKE_HOME_DIRECTORY}/threads
        ${CMAKE_HOME_DIRECTORY}/machine
)
add_definitions(-DTHREADS)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(monitor_nachos ${monitorCPP} ${threadsCPP})