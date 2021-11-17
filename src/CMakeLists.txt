
################################
# setting path to include files 
################################

include(FindPkgConfig)
find_package(OpenCV REQUIRED)

include_directories( 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
    ${OpenCV_INCLUDE_DIRS}
) 

######################
# compiled libraries
######################

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

message(STATUS "${CMAKE_SOURCE_DIR}")
message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")


message(STATUS "OpenCV Version: ${OpenCV_VERSION}")

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
