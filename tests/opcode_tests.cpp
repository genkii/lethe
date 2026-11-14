#include <gtest/gtest.h>
#include <lethe/interpreter/op_code.hpp>

TEST(OpcodeTests, Conversion)
{
    OpCode opcode1 = OpCode::XORI;

    EXPECT_EQ(op_code_to_u8(opcode1), 0);

    OpCode opcode2 = OpCode::ADDI;

    EXPECT_EQ(op_code_to_u8(opcode2), 1);

    OpCode opcode3 = OpCode::SUBI;

    EXPECT_EQ(op_code_to_u8(opcode3), 2);

    OpCode opcode4 = OpCode::SWAP;

    EXPECT_EQ(op_code_to_u8(opcode4), 3);

    OpCode opcode5 = OpCode::ROTR;

    EXPECT_EQ(op_code_to_u8(opcode5), 4);

    OpCode opcode6 = OpCode::ROTL;

    EXPECT_EQ(op_code_to_u8(opcode6), 5);
}