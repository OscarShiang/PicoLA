project(PicoLA_test)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

set(TEST_SOURCE
  TestVec.cpp
  TestMat.cpp
)

list(TRANSFORM TEST_SOURCE REPLACE ".cpp" "")
set(TEST_TARGET ${TEST_SOURCE})

foreach(target ${TEST_TARGET})
  add_executable(${target} ${target})
  target_link_libraries(${target} GTest::gtest_main)
  target_include_directories(${target} PUBLIC ${CMAKE_SOURCE_DIR}/include)
  gtest_discover_tests(${target} TEST_LIST test)
endforeach()
