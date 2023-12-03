cmake_minimum_required(VERSION 3.10)
project(lab_6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp npc.cpp observer.cpp outlaw.cpp orc.cpp werewolf.cpp)

add_subdirectory(googletest)

add_executable(tests tests.cpp npc.cpp observer.cpp outlaw.cpp orc.cpp werewolf.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)