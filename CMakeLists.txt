cmake_minimum_required(VERSION 2.8)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME task1) 
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

#----------------------------------------------------------------------------
# Define project sources and includes
#----------------------------------------------------------------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

set(SRC_FILES ${PROJECT_SOURCE_DIR}/src/student.cpp
              ${PROJECT_SOURCE_DIR}/src/dean.cpp
              ${PROJECT_SOURCE_DIR}/src/group.cpp)

set(CMAKE_CXX_STANDARD 11)

add_library(dean ${SRC_FILES})
add_executable(demo ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(demo dean)

file(COPY ${PROJECT_SOURCE_DIR}/data/groups.csv DESTINATION ${PROJECT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/data/students.csv DESTINATION ${PROJECT_BINARY_DIR})
