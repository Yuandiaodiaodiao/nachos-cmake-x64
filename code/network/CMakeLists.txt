include(${CMAKE_HOME_DIRECTORY}/vm/vm_core.cmake)
include(${CMAKE_HOME_DIRECTORY}/threads/threads_core.cmake)
include(${CMAKE_HOME_DIRECTORY}/filesys/filesys_core.cmake)
include(${CMAKE_HOME_DIRECTORY}/userprog/userprog_core.cmake)

FILE(GLOB_RECURSE monitorCPP
        nettest.cc
        post.cc
        network.cc

        )

include_directories(
        ${CMAKE_HOME_DIRECTORY}/network
)
add_definitions(-DNETWORK)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(network_nachos ${threadsCPP} ${filesysCPP} ${userprogCPP} ${CMAKE_HOME_DIRECTORY}/threads/main.cc)