#include <lethe/interpreter/error/error_manager.hpp>
#include <print>

void ErrorManager::report(ErrorType type, const std::string& message)
{
    std::println("ERROR: {type}, {message}", type, message);
}