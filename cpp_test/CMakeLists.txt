cmake_minimum_required(VERSION 3.21)

project(
    cpp_test
    VERSION 0.1
    DESCRIPTION "test cpp project"
    LANGUAGES CXX
)

add_executable(
    test_all
    EXCLUDE_FROM_ALL
)

target_include_directories(
    test_all
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_sources(
    test_all
    PRIVATE
    test/stop_watch_test.cc src/stop_watch.cc
)

target_link_libraries(
    test_all
    gtest gtest_main
)
