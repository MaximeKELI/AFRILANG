cmake_minimum_required(VERSION 3.14)
project(AFRILANG VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Sources du compilateur
set(AFRILANG_SOURCES
    src/lexer/lexer.cpp
    src/parser/parser.cpp
    src/semantic/analyzer.cpp
    src/codegen/codegen.cpp
)

add_executable(afrilang main.cpp ${AFRILANG_SOURCES})

target_include_directories(afrilang PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(afrilang PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Installation
install(TARGETS afrilang DESTINATION bin)

# Cible pour compiler les exemples
add_custom_target(examples
    COMMAND ${CMAKE_BINARY_DIR}/afrilang ${CMAKE_SOURCE_DIR}/examples/hello.afr --run
    COMMAND ${CMAKE_BINARY_DIR}/afrilang ${CMAKE_SOURCE_DIR}/examples/oop.afr --run
    COMMAND ${CMAKE_BINARY_DIR}/afrilang ${CMAKE_SOURCE_DIR}/examples/conditions.afr --run
    COMMAND ${CMAKE_BINARY_DIR}/afrilang ${CMAKE_SOURCE_DIR}/examples/inheritance.afr --run
    COMMAND ${CMAKE_BINARY_DIR}/afrilang ${CMAKE_SOURCE_DIR}/examples/functions.afr --run
    DEPENDS afrilang
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Compilation et exécution des exemples AFRILANG"
)
