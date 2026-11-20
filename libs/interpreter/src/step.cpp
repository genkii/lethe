#include <bit>
#include <cstdint>
#include <lethe/interpreter/op_code.hpp>
#include <lethe/interpreter/runtime.hpp>

bool Runtime::step()
{
    OpCode opcode = static_cast<OpCode>(fetch_byte());

    switch (opcode)
    {
    case OpCode::XORI:
    {
        std::uint8_t target_register = fetch_byte();
        std::uint64_t value = fetch_word();
        int_registers[target_register] ^= value;
        break;
    }

    case OpCode::ADDI:
    {
        std::uint8_t target_register = fetch_byte();
        std::uint64_t value = fetch_word();
        int_registers[target_register] += value;
        break;
    }

    case OpCode::SUBI:
    {
        std::uint8_t target_register = fetch_byte();
        std::uint64_t value = fetch_word();
        int_registers[target_register] -= value;
        break;
    }

    case OpCode::SWAP:
    {
        std::uint8_t source_register = fetch_byte();
        std::uint8_t target_register = fetch_byte();

        auto value1 = int_registers[source_register];
        auto value2 = int_registers[target_register];

        int_registers[source_register] = value2;
        int_registers[target_register] = value1;

        break;
    }

    case OpCode::ROTR:
    {
        std::uint8_t target_register = fetch_byte();
        std::uint64_t value = fetch_word();

        int_registers[target_register] = std::rotr(int_registers[target_register], value);

        break;
    }

    case OpCode::ROTL:
    {
        std::uint8_t target_register = fetch_byte();
        std::uint64_t value = fetch_word();

        int_registers[target_register] = std::rotl(int_registers[target_register], value);

        break;
    }

    case OpCode::POP:
    {
        std::uint8_t target_register = fetch_byte();

        if (memory.stack.size() == 0)
        {
            error_manager.report(ErrorType::STACK_UNDERFLOW, "Cant pop number from empty stack");
            return false;
        }

        if (int_registers[target_register] != 0)
        {
            error_manager.report(ErrorType::REVERSIBILITY_VIOLATION,
                                 "Cant reverse operation when register isnt empty");
            return false;
        }

        int_registers[target_register] ^= memory.stack.pop_stack();

        break;
    }

    case OpCode::PUSH:
    {
        std::uint8_t target_register = fetch_byte();
        memory.stack.push_stack(int_registers[target_register]);
        int_registers[target_register] = 0;
        break;
    }

    case OpCode::PUSHI:
    {
        std::uint64_t value = fetch_word();
        memory.stack.push_stack(value);
        break;
    }

    default:
        return false;
    }

    return true;
}