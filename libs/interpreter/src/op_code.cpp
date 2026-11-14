#include <cstdint>
#include <lethe/interpreter/op_code.hpp>

std::uint8_t op_code_to_u8(OpCode op_code)
{
    return static_cast<std::uint8_t>(op_code);
}