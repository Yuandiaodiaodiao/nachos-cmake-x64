project(nathos)
cmake_minimum_required(VERSION 3.10)
execute_process(COMMAND rm ${CMAKE_CURRENT_SOURCE_DIR}/threads/switch.s)
execute_process(COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/build-switch.sh ${CMAKE_CURRENT_SOURCE_DIR})


#添加对.s的编译
ENABLE_LANGUAGE(ASM)
# 32bit编译

#原有的警告
#set(CMAKE_CXX_FLAGS "-m32 -Wall -Wshadow")
set(CMAKE_CXX_FLAGS "-m32")
#set(CMAKE_ASM_FLAGS "-m32 -Wall -Wshadow")
set(CMAKE_ASM_FLAGS "-m32")
add_definitions(-DHOST_i386)
add_definitions(-DHOST_LINUX)
add_definitions(-DCHANGED)


add_subdirectory(threads)
add_subdirectory(ass3)
add_subdirectory(bin)
add_subdirectory(filesys)
add_subdirectory(lab3)
add_subdirectory(lab7-8)
add_subdirectory(monitor)
add_subdirectory(network)
add_subdirectory(userprog)
add_subdirectory(vm)
add_subdirectory(lab2)
add_subdirectory(lab5)





























#add_definitions(-DMAKEFILE_THREADS)
#add_definitions(-DMAKEFILE_THREADS_LOCAL)
#add_definitions(-DMAKEFILE_COMMON)



#set(CMAKE_ASM_COMPILER "/usr/bin/as")
#add_definitions("-DCHANGED -DTHREADS -DHOST_i386 -DHOST_LINUX -c ")

#set(CMAKE_EXE_LINKER_FLAGS "-m32")
#option(MAKEFILE_USERPROG_LOCAL " "  ON)
#option(MAKE_FILE_FILESYS_LOCAL " "  ON)
#if(MAKEFILE_USERPROG_LOCAL)
#    message(STATUS "!!!!!!!!!!!!!!nothine")
#
#else()
#    add_definitions(-DMAKEFILE_USERPROG_LOCAL)
#    message(STATUS "DEF MAKEFILE_USERPROG_LOCAL")
#endif()
#if(MAKE_FILE_FILESYS_LOCAL)
#    add_definitions(-DUSER_PROGRAM)
#else()
#    add_definitions(-DUSER_PROGRAM)
#    add_definitions(-DFILESYS_NEEDED)
#    add_definitions(-DFILESYS_STUB)
#endif()
#project(main)
#
##add_subdirectory(threads)
##add_subdirectory(machine)
##add_compile_options(-std=c99)
#file(GLOB_RECURSE  ThreadsFile  ./threads/*.h ./threads/*.cc ./threads/*.s)
##aux_source_directory(. DIRSRCS)
#include_directories(. threads machine userprog filesys)
#add_subdirectory(threads)
#add_subdirectory(machine)
#
#
#
#add_executable(main ${ThreadsFile} )
##add_executable(main ./threads/main.cc )
#target_link_libraries(main   Machine -m32)

#target_link_libraries(main Threads -m32)
#include_directories(machine)
#add_definitions(-DUSER_PROGRAM)

#add_definitions(-DUSER_PROGRAM)

#FILE(GLOB_RECURSE  threadsCPP
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/switch.s
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/main.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/list.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/scheduler.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/synch.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/synchlist.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/system.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/thread.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/utility.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/threadtest.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/threads/synchtest.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/machine/interrupt.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/machine/sysdep.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/machine/stats.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/machine/timer.cc
#        )
#FILE(GLOB_RECURSE  machineH
#        )
#FILE("./machine" machineH "*.h")
#aux_source_directory(threads tDIR_SRCS)
#aux_source_directory(machine mDIR_SRCS)
#add_executable(main ${tDIR_SRCS} ${mDIR_SRCS} ${threadsH} ${machineH})
#target_link_libraries(main -m32)
#SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/threads)

#SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/machine)
#add_executable(threads_nachos1 ${threadsCPP})