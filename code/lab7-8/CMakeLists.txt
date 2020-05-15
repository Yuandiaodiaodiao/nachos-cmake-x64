set(MAKEFILE_USERPROG_LOCAL ON)
include(${CMAKE_HOME_DIRECTORY}/threads/threads_core.cmake)


FILE(GLOB_RECURSE userprogCPP
        ${CMAKE_HOME_DIRECTORY}/userprog/addrspace.cc
        ${CMAKE_HOME_DIRECTORY}/userprog/bitmap.cc
        exception.cc
        ${CMAKE_HOME_DIRECTORY}/userprog/progtest.cc
        ${CMAKE_HOME_DIRECTORY}/machine/console.cc
        ${CMAKE_HOME_DIRECTORY}/machine/machine.cc
        ${CMAKE_HOME_DIRECTORY}/machine/mipssim.cc
        ${CMAKE_HOME_DIRECTORY}/machine/translate.cc

        )

include_directories(
        ${CMAKE_HOME_DIRECTORY}/filesys
        ${CMAKE_HOME_DIRECTORY}/userprog
        ${CMAKE_HOME_DIRECTORY}/bin
)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DUSER_PROGRAM)
add_definitions(-DFILESYS_NEEDED -DFILESYS_STUB)
add_definitions(-w)

add_executable(lab7-8 ${userprogCPP} ${filesysCPP}  ${threadsCPP} ${CMAKE_HOME_DIRECTORY}/threads/main.cc)