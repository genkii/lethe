

#pragma once

#include <string_view>

enum class ErrorType
{
    STACK_UNDERFLOW,
    INVALID_OPCODE,
    INVALID_REGISTER,
    REVERSIBILITY_VIOLATION,
};

std::string_view error_type_to_string(ErrorType error);