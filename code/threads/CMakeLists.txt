include(threads_core.cmake)
message(STATUS "FILES= ${threadsCPP}")
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(threads_nachos ${threadsCPP} main.cc)
