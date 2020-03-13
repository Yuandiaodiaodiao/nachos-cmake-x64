include(${CMAKE_HOME_DIRECTORY}/threads/threads_core.cmake)
FILE(GLOB_RECURSE lab7CPP
        ${CMAKE_HOME_DIRECTORY}/*/addrspace.cc
        ${CMAKE_HOME_DIRECTORY}/*/bitmap.cc
        exception.cc
        ${CMAKE_HOME_DIRECTORY}/*/progtest.cc
        ${CMAKE_HOME_DIRECTORY}/*/console.cc
        ${CMAKE_HOME_DIRECTORY}/*/machine.cc
        ${CMAKE_HOME_DIRECTORY}/*/mipssim.cc
        ${CMAKE_HOME_DIRECTORY}/*/translate.cc
        )

include_directories(
        ${CMAKE_HOME_DIRECTORY}/bin
        ${CMAKE_HOME_DIRECTORY}/userprog
        ${CMAKE_HOME_DIRECTORY}/filesys
)
add_definitions(-DUSER_PROGRAM)
if (MAKE_FILE_FILESYS_LOCAL)
else ()
    add_definitions(-DFILESYS_NEEDED -DFILESYS_STUB)
endif ()
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(lab7_nachos ${lab7CPP} ${threadsCPP} ${CMAKE_HOME_DIRECTORY}/threads/main.cc)