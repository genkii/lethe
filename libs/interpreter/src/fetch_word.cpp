#include <cstdint>
#include <lethe/interpreter/runtime.hpp>

std::uint64_t Runtime::fetch_word()
{

    std::uint64_t result = 0;

    for (int i = 0; i < 8; ++i)
    {
        result = (result << 8) | fetch_byte();
    }

    return result;
}