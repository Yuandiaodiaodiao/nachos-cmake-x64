include(${CMAKE_HOME_DIRECTORY}/threads/threads_core.cmake)
include(filesys_core.cmake)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(filesys_nachos ${filesysCPP} ${threadsCPP} ${CMAKE_HOME_DIRECTORY}/filesys/main.cc)