FILE(GLOB_RECURSE filesysCPP
        ${CMAKE_HOME_DIRECTORY}/userprog/bitmap.cc
        ${CMAKE_HOME_DIRECTORY}/filesys/directory.cc
        ${CMAKE_HOME_DIRECTORY}/filesys/filehdr.cc
        ${CMAKE_HOME_DIRECTORY}/filesys/filesys.cc
        ${CMAKE_HOME_DIRECTORY}/filesys/fstest.cc
        ${CMAKE_HOME_DIRECTORY}/filesys/openfile.cc
        ${CMAKE_HOME_DIRECTORY}/filesys/synchdisk.cc
        ${CMAKE_HOME_DIRECTORY}/machine/disk.cc
        )

include_directories(
        ${CMAKE_HOME_DIRECTORY}/userprog
        ${CMAKE_HOME_DIRECTORY}/filesys
)
