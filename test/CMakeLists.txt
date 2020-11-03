cmake_minimum_required(VERSION 3.18)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(runTest CustomerTest.cpp ../src/Customer.cpp)
target_link_libraries(runTest ${GTEST_LIBRARIES})
