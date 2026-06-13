cmake_minimum_required(VERSION 3.14)
project(AFRILANG VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(AFRILANG_SOURCES
    src/lexer/lexer.cpp
    src/parser/parser.cpp
    src/semantic/analyzer.cpp
    src/codegen/codegen.cpp
    src/utils/compiler.cpp
    src/utils/cli.cpp
    src/utils/diagnostics.cpp
    src/utils/project.cpp
    src/utils/stdlib_registry.cpp
    src/lsp/server.cpp
)

add_executable(afrilang main.cpp ${AFRILANG_SOURCES})
target_include_directories(afrilang PRIVATE ${CMAKE_SOURCE_DIR}/include)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(afrilang PRIVATE -Wall -Wextra -Wpedantic)
endif()

install(TARGETS afrilang DESTINATION bin)
install(DIRECTORY runtime/ DESTINATION share/afrilang/runtime)
install(DIRECTORY stdlib/ DESTINATION share/afrilang/stdlib OPTIONAL)

# Tests unitaires du compilateur
add_executable(afrilang_tests tests/test_compiler.cpp ${AFRILANG_SOURCES})
target_include_directories(afrilang_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_definitions(afrilang_tests PRIVATE AFRILANG_TESTING=1)

enable_testing()
add_test(NAME compiler_unit_tests COMMAND afrilang_tests)
add_test(NAME compiler_integration COMMAND afrilang test ${CMAKE_SOURCE_DIR})

# Exemples
add_custom_target(examples
    COMMAND ${CMAKE_BINARY_DIR}/afrilang test ${CMAKE_SOURCE_DIR}
    DEPENDS afrilang
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Compilation et tests des exemples AFRILANG"
)
