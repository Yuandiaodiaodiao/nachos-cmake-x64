include(lab2_core.cmake)
include_directories(.)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include(${CMAKE_HOME_DIRECTORY}/threads/threads_core.cmake)

# 移除
list(REMOVE_ITEM threadsCPP ${CMAKE_HOME_DIRECTORY}/threads/scheduler.cc)

add_executable(lab2_nachos ./scheduler.cc ${threadsCPP} ${CMAKE_HOME_DIRECTORY}/threads/main.cc)