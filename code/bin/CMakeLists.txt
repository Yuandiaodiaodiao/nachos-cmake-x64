FILE(GLOB_RECURSE coff2noffCPP
        coff2noff.c

        )
FILE(GLOB_RECURSE coff2flatCPP
        coff2flat.c

        )
include_directories(
        ${CMAKE_HOME_DIRECTORY}/threads
        ${CMAKE_HOME_DIRECTORY}/bin
)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(coff2noff ${coff2noffCPP})
add_executable(coff2flat ${coff2flatCPP})