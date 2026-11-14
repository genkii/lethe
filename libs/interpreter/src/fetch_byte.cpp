#include <cstdint>
#include <lethe/interpreter/runtime.hpp>

std::uint8_t Runtime::fetch_byte()
{
    std::uint8_t byte = program[pc];
    pc++;
    return byte;
}