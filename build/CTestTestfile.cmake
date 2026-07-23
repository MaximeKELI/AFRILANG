# CMake generated Testfile for 
# Source directory: /home/admin20/AFRILANG
# Build directory: /home/admin20/AFRILANG/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(compiler_unit_tests "/home/admin20/AFRILANG/build/afrilang_tests")
set_tests_properties(compiler_unit_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/admin20/AFRILANG/CMakeLists.txt;109;add_test;/home/admin20/AFRILANG/CMakeLists.txt;0;")
add_test(compiler_integration "/home/admin20/AFRILANG/build/afrilang" "test" "/home/admin20/AFRILANG")
set_tests_properties(compiler_integration PROPERTIES  _BACKTRACE_TRIPLES "/home/admin20/AFRILANG/CMakeLists.txt;110;add_test;/home/admin20/AFRILANG/CMakeLists.txt;0;")
