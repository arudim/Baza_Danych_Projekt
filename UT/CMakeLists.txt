cmake_minimum_required(VERSION 3.16)

project(test1 LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ($ENV{GOOGLETEST_DIR})
    get_filename_component(_GTEST_BASE $ENV{GOOGLETEST_DIR} REALPATH)
elseif (EXISTS "${CMAKE_SOURCE_DIR}/googletest") # set by QC
    get_filename_component(_GTEST_BASE "${CMAKE_SOURCE_DIR}/googletest" REALPATH) # set by QC
elseif (UNIX AND EXISTS "/usr/src/gtest")
    set(_GTEST_BASE "/usr/src/gtest")
endif()

if (_GTEST_BASE AND NOT EXISTS "${_GTEST_BASE}/googletest/src/gtest-all.cc"
        OR NOT EXISTS "${_GTEST_BASE}/googlemock/src/gmock-all.cc")
    message(ERROR "Missing source components (gtest-all.cc and/or gmock-all.cc).")
endif()

find_package(Threads REQUIRED)

include_directories(
    ${_GTEST_BASE}/googletest ${_GTEST_BASE}/googletest/include
    ${_GTEST_BASE}/googlemock ${_GTEST_BASE}/googlemock/include
)
add_executable(test1 main.cpp tst_test1.cpp
               ${_GTEST_BASE}/googletest/src/gtest-all.cc
               ${_GTEST_BASE}/googlemock/src/gmock-all.cc
           )

add_test(NAME test1 COMMAND test1)
target_link_libraries(test1 PRIVATE Threads::Threads)
