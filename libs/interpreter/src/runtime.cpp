#include <filesystem>
#include <fstream>
#include <iterator>
#include <lethe/interpreter/runtime.hpp>
#include <vector>

Runtime::Runtime(std::filesystem::path path)
{
    std::ifstream file(path);

    for (auto i = 0; i < 16; i++)
    {
        int_registers[i] = 0;
    }

    program = {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
}

Runtime::Runtime(std::vector<std::uint8_t> program)
{
    for (auto i = 0; i < 16; i++)
    {
        int_registers[i] = 0;
    }

    this->program = program;
}

void Runtime::start()
{
    while (pc < program.size())
    {
        if (!step())
            return;
    }
}

std::array<std::uint64_t, 16> Runtime::debug_get_registers()
{
    return this->int_registers;
}