cmake_minimum_required( VERSION 2.6.4 )
project(Code4Life)

include_directories(inc)

add_subdirectory(lib/gtest)

include_directories(lib/gtest/googlemock/include/gmock lib/gtest/googletest/include/gtest tests/mocks)

add_subdirectory(src)

add_subdirectory(tests)