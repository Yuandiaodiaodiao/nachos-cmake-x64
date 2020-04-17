include_directories(${CMAKE_HOME_DIRECTORY}/lab5)
include(${CMAKE_HOME_DIRECTORY}/threads/threads_core.cmake)
include(lab5_core.cmake)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(lab5_nachos ${lab5CPP} ${threadsCPP} ${CMAKE_HOME_DIRECTORY}/lab5/main.cc)