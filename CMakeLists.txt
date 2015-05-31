cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#*****************************************
# Battleship project
# Alex Kyriazakos
#*****************************************
set_property(GLOBAL PROPERTY USE_FOLDERS ON) #not needed right now

project(Battleship)

#Set output path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR} CACHE PATH "")

#Turn on C++11 for Unix systems
if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif(UNIX)

#Gather source and header files
#SRC_FILES variable has the names of all source files, HDR_FILES ...
#CMAKE_CURRENT_SOURCE_DIR shows the current directory of the active CMakeLists.txt
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Battleship/*.cpp) 
file(GLOB HDR_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Battleship/*.h)

#This line creates the actual project
add_executable(BattleShip 
				${SRC_FILES} 
				${HDR_FILES}
				)
#set executable to be generated in lower case (optional)
string(TOLOWER BattleShip _filename)
set_target_properties(BattleShip PROPERTIES OUTPUT_NAME ${_filename})

#Create separate folder for Headers (only for the IDE)
source_group("Headers" FILES ${${_program}_HDR_FILES})
		
