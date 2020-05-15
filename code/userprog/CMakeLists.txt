set(MAKEFILE_USERPROG_LOCAL ON)
include(${CMAKE_HOME_DIRECTORY}/threads/threads_core.cmake)


include(userprog_core.cmake)



SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DUSER_PROGRAM)
add_definitions(-DFILESYS_NEEDED -DFILESYS_STUB)
add_definitions(-w)

add_executable(userprog_nachos ${userprogCPP} ${filesysCPP}  ${threadsCPP} ${CMAKE_HOME_DIRECTORY}/threads/main.cc)