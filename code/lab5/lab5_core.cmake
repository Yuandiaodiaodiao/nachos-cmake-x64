set(MAKEFILE_FILESYS_LOCAL ON)
FILE(GLOB_RECURSE lab5CPP
        ${CMAKE_HOME_DIRECTORY}/userprog/bitmap.cc
        ${CMAKE_HOME_DIRECTORY}/filesys/directory.cc
        ${CMAKE_HOME_DIRECTORY}/lab5/filehdr.cc
        ${CMAKE_HOME_DIRECTORY}/lab5/filesys.cc
        ${CMAKE_HOME_DIRECTORY}/lab5/fstest.cc
        ${CMAKE_HOME_DIRECTORY}/lab5/openfile.cc
        ${CMAKE_HOME_DIRECTORY}/filesys/synchdisk.cc
        ${CMAKE_HOME_DIRECTORY}/machine/disk.cc
        )

    include_directories(
            ${CMAKE_HOME_DIRECTORY}/userprog
            ${CMAKE_HOME_DIRECTORY}/filesys
    )
    add_definitions(-DFILESYS_NEEDED -DFILESYS)

