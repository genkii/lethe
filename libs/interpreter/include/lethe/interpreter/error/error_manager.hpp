#include <lethe/interpreter/error/error_type.hpp>
#include <string>

class ErrorManager
{
  public:
    void report(ErrorType type, const std::string& message);
};
