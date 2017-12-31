project(space_shooter CXX)
#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

######################################################
# Output directories for binaries, libs and archives #
######################################################
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

############
# TinyXML2 #
############
file(GLOB TINY_XML_SOURCE ${CMAKE_SOURCE_DIR}/tinyxml2/tinyxml2.cpp)
file(GLOB TINY_XML_HEADER ${CMAKE_SOURCE_DIR}/tinyxml2/tinyxml2.h)

include_directories(${CMAKE_SOURCE_DIR}/tinyxml2)

add_library(TINYXML2_LIB SHARED ${TINY_XML_SOURCE} ${TINY_XML_HEADER})

#########
# Box2D #
#########
file(GLOB_RECURSE BOX2D_SOURCES ${CMAKE_SOURCE_DIR}/Box2D/*.cpp)
file(GLOB_RECURSE BOX2D_HEADERS ${CMAKE_SOURCE_DIR}/Box2D/*.h)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Box2D)
include_directories(${CMAKE_SOURCE_DIR}/Box2D/*)

add_library(BOX2D_LIB ${BOX2D_SOURCES} ${BOX2D_HEADERS})

###############
# Add Entityx #
###############
set(ENTITYX_LIB "/usr/local/lib/libentityx.so")
set(ENTITYX_INCLUDE "/usr/local/include/entityx/")

include_directories(${ENTITYX_INCLUDE})

#######################
# Detect and add SFML #
#######################
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

file(GLOB_RECURSE SFML_HEADERS /home/mfb/codes/libraries/SFML-2.4.2/include/*)

#############
# TMXPARSER #
#############
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(TmxParser)

include_directories(${TMXPARSER_INCLUDE_DIR}/tmxparser)

message("\nTMXPARSER_LIBRARY: " ${TMXPARSER_LIBRARY})
message("\nTMXPARSER_INCLUDE_DIR: " ${TMXPARSER_INCLUDE_DIR})
message("\n")

############################
# Source files and headers #
############################
file(GLOB LIB_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB LIB_HEADERS ${CMAKE_SOURCE_DIR}/src/*.hpp)
include_directories(${CMAKE_SOURCE_DIR}/src/)

add_library(PROJECT_LIB ${LIB_SOURCES} ${LIB_HEADERS})

######################
# Create executables #
######################
set(EXECUTABLE_NAME "main")
add_executable(${EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)

######################################################
# Last step link all the libraries to the executable #
######################################################
target_link_libraries(${EXECUTABLE_NAME} PROJECT_LIB ${SFML_LIBRARIES} BOX2D_LIB ${TMXPARSER_LIBRARY} TINYXML2_LIB ${ENTITYX_LIB})
