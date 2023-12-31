cmake_minimum_required(VERSION 2.8.12)

project(TurnCoordinator)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES
                ${PROJECT_SOURCE_DIR}/main.cpp
                ${PROJECT_SOURCE_DIR}/VertexArrayObject.cpp
                ${PROJECT_SOURCE_DIR}/shaderProgram.cpp
                ${PROJECT_SOURCE_DIR}/glad.c
                ${PROJECT_SOURCE_DIR}/texturemanager.cpp
                ${PROJECT_SOURCE_DIR}/TurnCordinator.cpp
                ${PROJECT_SOURCE_DIR}/TCManager.cpp
                )


set(PROJECT_HEADERS
                ${PROJECT_INCLUDE_DIR}/shaderProgram.hpp
                ${PROJECT_INCLUDE_DIR}/VertexArrayObject.hpp
                ${PROJECT_INCLUDE_DIR}/VertexTypes.hpp
                ${PROJECT_INCLUDE_DIR}/texturemanager.hpp
                ${PROJECT_INCLUDE_DIR}/TurnCordinator.hpp
                ${PROJECT_INCLUDE_DIR}/TCManager.hpp
                )



find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} glfw)