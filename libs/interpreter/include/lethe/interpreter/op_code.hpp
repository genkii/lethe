#include <cstdint>

enum class OpCode : std::uint8_t
{
    XORI = 0x00,

    ADDI = 0x01,
    SUBI = 0x02,

    SWAP = 0x03,
    ROTR = 0x04,
    ROTL = 0x05,

    POP = 0x06,
    PUSH = 0x07,
    PUSHI = 0x08,
};

std::uint8_t op_code_to_u8(OpCode op_code);