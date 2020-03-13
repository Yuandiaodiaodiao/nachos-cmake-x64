include(${CMAKE_HOME_DIRECTORY}/threads/threads_core.cmake)
include(userprog_core.cmake)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(userprog_nachos ${userprogCPP} ${threadsCPP} ${CMAKE_HOME_DIRECTORY}/threads/main.cc)