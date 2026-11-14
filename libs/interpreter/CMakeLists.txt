add_library(lethe_interpreter 
    include/lethe/interpreter/runtime.hpp
    src/runtime.cpp
    include/lethe/interpreter/op_code.hpp
    src/op_code.cpp
    src/step.cpp
    src/fetch_byte.cpp
    src/fetch_word.cpp
    include/lethe/interpreter/memory/memory.hpp
    include/lethe/interpreter/memory/stack.hpp
    src/memory/stack.cpp
    include/lethe/interpreter/error/error_type.hpp
    include/lethe/interpreter/error/error_manager.hpp
    src/error/error_manager.cpp
)

target_include_directories(lethe_interpreter
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(lethe_interpreter
    PRIVATE
)