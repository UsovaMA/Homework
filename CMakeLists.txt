cmake_minimum_required(VERSION 2.6)

project(Is_Correct)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../)
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB CPPS "*.cpp")

add_executable(${PROJECT_NAME} ${CPPS})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)