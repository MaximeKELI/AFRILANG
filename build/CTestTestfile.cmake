# CMake generated Testfile for 
# Source directory: /home/maxime/AFRILANG
# Build directory: /home/maxime/AFRILANG/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(compiler_unit_tests "/home/maxime/AFRILANG/build/afrilang_tests")
set_tests_properties(compiler_unit_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/maxime/AFRILANG/CMakeLists.txt;64;add_test;/home/maxime/AFRILANG/CMakeLists.txt;0;")
add_test(compiler_integration "/home/maxime/AFRILANG/build/afrilang" "test" "/home/maxime/AFRILANG")
set_tests_properties(compiler_integration PROPERTIES  _BACKTRACE_TRIPLES "/home/maxime/AFRILANG/CMakeLists.txt;65;add_test;/home/maxime/AFRILANG/CMakeLists.txt;0;")
