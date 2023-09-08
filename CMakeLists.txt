cmake_minimum_required(VERSION 3.26)
project(BankKata)

set(CMAKE_CXX_STANDARD 17)

add_executable(BankKata main.cpp
        AccountService.cc
        AccountService.h
        infrastructure/Clock.cc
        infrastructure/Clock.h
        infrastructure/Console.cc
        infrastructure/Console.h
        mocks/MockConsole.cc
        mocks/MockConsole.h
        mocks/MockClock.cc
        mocks/MockClock.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

target_link_libraries(BankKata gtest gtest_main gmock)
include(GoogleTest)
gtest_discover_tests(BankKata)