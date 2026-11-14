include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(lethe_tests
    opcode_tests.cpp
    runtime_tests.cpp
)

target_link_libraries(lethe_tests
    PRIVATE
        lethe_interpreter
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(lethe_tests)