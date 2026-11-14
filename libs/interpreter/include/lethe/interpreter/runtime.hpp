#include <array>
#include <cstdint>
#include <filesystem>
#include <lethe/interpreter/error/error_manager.hpp>
#include <lethe/interpreter/memory/memory.hpp>
#include <vector>

class Runtime
{
  private:
    std::vector<std::uint8_t> program;
    std::array<std::uint64_t, 16> int_registers;

    std::uint64_t pc = 0;

    bool step();
    std::uint8_t fetch_byte();
    std::uint64_t fetch_word();

  public:
    Memory memory{};
    ErrorManager error_manager{};
    Runtime(std::filesystem::path path);
    Runtime(std::vector<std::uint8_t> program);
    void start();

    std::array<std::uint64_t, 16> debug_get_registers();
};
