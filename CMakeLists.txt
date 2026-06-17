cmake_minimum_required(VERSION 3.14)
project(AFRILANG VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

configure_file(
    ${CMAKE_SOURCE_DIR}/include/afrilang/version.hpp.in
    ${CMAKE_BINARY_DIR}/generated/afrilang/version.hpp
    @ONLY
)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(AFRILANG_SOURCES
    src/lexer/lexer.cpp
    src/parser/parser.cpp
    src/semantic/analyzer.cpp
    src/codegen/codegen.cpp
    src/utils/compiler.cpp
    src/utils/cli.cpp
    src/utils/diagnostics.cpp
    src/utils/utf8.cpp
    src/utils/i18n.cpp
    src/utils/semver.cpp
    src/utils/sandbox.cpp
    src/utils/security.cpp
    src/utils/project.cpp
    src/utils/stdlib_registry.cpp
    src/utils/stdlib_catalog.cpp
    src/utils/medium_catalog.cpp
    src/utils/complex_catalog.cpp
    src/utils/formatter.cpp
    src/utils/pkg.cpp
    src/utils/hash.cpp
    src/utils/cache.cpp
    src/utils/debug.cpp
    src/utils/debug_meta.cpp
    src/utils/js_codegen.cpp
    src/utils/env.cpp
    src/utils/educational.cpp
    src/repl/repl.cpp
    src/serve/server.cpp
    src/lsp/server.cpp
)

add_executable(afrilang main.cpp ${AFRILANG_SOURCES})
target_include_directories(afrilang PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/generated
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(afrilang PRIVATE -Wall -Wextra -Wpedantic)
endif()

find_package(OpenSSL QUIET)
if(OpenSSL_FOUND)
    target_link_libraries(afrilang OpenSSL::SSL OpenSSL::Crypto)
else()
    target_link_libraries(afrilang ssl crypto)
endif()

option(AFRILANG_ENABLE_COVERAGE "Enable coverage reporting" OFF)

install(TARGETS afrilang DESTINATION bin)
install(DIRECTORY runtime/ DESTINATION share/afrilang/runtime)
install(DIRECTORY stdlib/ DESTINATION share/afrilang/stdlib OPTIONAL)

# Tests unitaires du compilateur
add_executable(afrilang_tests tests/test_compiler.cpp ${AFRILANG_SOURCES})
target_include_directories(afrilang_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/generated
)
target_compile_definitions(afrilang_tests PRIVATE AFRILANG_TESTING=1)

# SDL2 runtime (ui.hpp) is used by one unit test
find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
    pkg_check_modules(SDL2 QUIET sdl2)
    pkg_check_modules(SDL2TTF QUIET SDL2_ttf)
    if(SDL2_FOUND AND SDL2TTF_FOUND)
        target_include_directories(afrilang_tests PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
        target_link_libraries(afrilang_tests ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARIES})
        target_compile_options(afrilang_tests PRIVATE ${SDL2_CFLAGS_OTHER} ${SDL2TTF_CFLAGS_OTHER})
    endif()
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(afrilang_tests PRIVATE -Wall -Wextra -Wpedantic)
    if(OpenSSL_FOUND)
        target_link_libraries(afrilang_tests OpenSSL::SSL OpenSSL::Crypto)
    else()
        target_link_libraries(afrilang_tests ssl crypto)
    endif()
    if(AFRILANG_ENABLE_COVERAGE)
        target_compile_options(afrilang PRIVATE --coverage)
        target_link_options(afrilang PRIVATE --coverage)
        target_compile_options(afrilang_tests PRIVATE --coverage)
        target_link_options(afrilang_tests PRIVATE --coverage)
    endif()
endif()

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
