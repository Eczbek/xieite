cmake_minimum_required(VERSION 3.25)

set(PROJECT_NAME xieite)
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/pp/ver.hpp" PROJECT_VER_SRC)
string(REGEX MATCH "define [A-Z_]+_MAJOR ([0-9]+)" _ ${PROJECT_VER_SRC})
set(PROJECT_VERSION_MAJOR ${CMAKE_MATCH_1})
string(REGEX MATCH "define [A-Z_]+_MINOR ([0-9]+)" _ ${PROJECT_VER_SRC})
set(PROJECT_VERSION_MINOR ${CMAKE_MATCH_1})
string(REGEX MATCH "define [A-Z_]+_PATCH ([0-9]+)" _ ${PROJECT_VER_SRC})
set(PROJECT_VERSION_PATCH ${CMAKE_MATCH_1})
project(
	${PROJECT_NAME}
	VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
	LANGUAGES CXX
)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(
	${PROJECT_NAME} INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
)
