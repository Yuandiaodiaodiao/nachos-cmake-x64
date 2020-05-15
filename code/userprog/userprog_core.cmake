set(MAKEFILE_USERPROG_LOCAL ON)
FILE(GLOB_RECURSE userprogCPP
        ${CMAKE_HOME_DIRECTORY}/userprog/addrspace.cc
        ${CMAKE_HOME_DIRECTORY}/userprog/bitmap.cc
        ${CMAKE_HOME_DIRECTORY}/userprog/exception.cc
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
