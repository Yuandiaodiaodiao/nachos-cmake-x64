include(${CMAKE_HOME_DIRECTORY}/threads/threads_core.cmake)
include(${CMAKE_HOME_DIRECTORY}/userprog/userprog_core.cmake)
include(vm_core.cmake)



SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(vm_nachos ${userprogCPP} ${threadsCPP} ${CMAKE_HOME_DIRECTORY}/threads/main.cc)