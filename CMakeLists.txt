cmake_minimum_required(VERSION 3.14)
project(leetcode-exercise)
set(CMAKE_CXX_STANDARD 11)

file( GLOB APP_SOURCES leetcode/*/*.cpp )

foreach( testsourcefile ${APP_SOURCES} )
    get_filename_component(exec_name ${testsourcefile} NAME_WE)
    message(STATUS "leetcode problem: ${exec_name}")
    add_executable( ${exec_name} ${testsourcefile} )
    # Make sure YourLib is linked to each app
    # target_link_libraries( ${testname} YourLib )
endforeach( testsourcefile ${APP_SOURCES} )