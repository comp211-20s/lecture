cmake_minimum_required(VERSION 3.10)

project(demo-project)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

##
### Test definitions ###
##

# Configuration for GoogleTest
configure_file(GoogleTestLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)
enable_testing()

##
### Source definitions ###
##
include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.c")
add_executable(${PROJECT_NAME} ${sources})

## Testing
list(REMOVE_ITEM sources "${PROJECT_SOURCE_DIR}/src/main.c")
file(GLOB tests "${PROJECT_SOURCE_DIR}/test/unit/*.cpp")
# foreach(file ${tests})
#     set(name)
#     get_filename_component(name ${file} NAME_WE)
#     add_executable("${name}_tests"
#             ${sources}
#             ${file}
#     )
#     target_link_libraries("${name}_tests" gtest_main)
#     add_test(NAME ${name} COMMAND "${name}_tests")
# endforeach()

## Testing Big
add_executable("all_tests" ${sources} ${tests})
target_link_libraries("all_tests" gtest_main)
add_test(NAME all_tests COMMAND "all_tests")
