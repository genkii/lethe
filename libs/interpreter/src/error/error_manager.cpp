#include <lethe/interpreter/error/error_manager.hpp>
#include <lethe/interpreter/error/error_type.hpp>
#include <print>
#include <string_view>

std::string_view error_type_to_string(ErrorType error)
{
    switch (error)
    {
    case ErrorType::INVALID_OPCODE:
        return "INVALID_OPCODE";

    case ErrorType::INVALID_REGISTER:
        return "INVALID_REGISTER";

    case ErrorType::REVERSIBILITY_VIOLATION:
        return "REVERSIBILITY_VIOLATION";

    case ErrorType::STACK_UNDERFLOW:
        return "STACK_UNDERFLOW";

    default:
        return "UNKNOWN_ERROR";
    }
}

void ErrorManager::report(ErrorType type, const std::string& message)
{
    std::println("ERROR: {}, {}", error_type_to_string(type), message);
}