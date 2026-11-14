cmake_minimum_required(VERSION 4.4.5)

project(lethe
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libs/interpreter)

include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.7.2
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(CLI11)

add_executable(lethe
    src/main.cpp
)


set_target_properties(lethe PROPERTIES
    OUTPUT_NAME charon
)

target_link_libraries(lethe PRIVATE
    lethe_interpreter
    CLI11::CLI11
)

include(CTest)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()