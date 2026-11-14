#include <gtest/gtest.h>
#include <lethe/interpreter/runtime.hpp>
#include <vector>

TEST(RuntimeTests, XORI)
{
    std::vector<std::uint8_t> program = {
        0x00, // XORI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05  // Byte 7
    };
    Runtime runtime = Runtime{program};
    runtime.start();

    std::uint64_t debug_register = runtime.debug_get_registers()[1];

    EXPECT_EQ(debug_register, 5);
}

TEST(RuntimeTests, XORI_REVERSE)
{
    std::vector<std::uint8_t> program = {
        0x00, // XORI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
        0x00, // XORI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
    };
    Runtime runtime = Runtime{program};
    runtime.start();

    std::uint64_t debug_register = runtime.debug_get_registers()[1];

    EXPECT_EQ(debug_register, 0);
}

TEST(RuntimeTests, ADDI)
{
    std::vector<std::uint8_t> program = {
        0x01, // ADDI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
        0x01, // ADDI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05  // Byte 7
    };
    Runtime runtime = Runtime{program};
    runtime.start();

    std::uint64_t debug_register = runtime.debug_get_registers()[1];

    EXPECT_EQ(debug_register, 10);
}

TEST(RuntimeTests, SUBI)
{
    std::vector<std::uint8_t> program = {
        0x01, // ADDI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x08, // Byte 7
        0x02, // SUBI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05  // Byte 7
    };
    Runtime runtime = Runtime{program};
    runtime.start();

    std::uint64_t debug_register = runtime.debug_get_registers()[1];

    EXPECT_EQ(debug_register, 3);
}

TEST(RuntimeTests, ADDI_REVERSE)
{
    std::vector<std::uint8_t> program = {
        0x01, // ADDI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
        0x02, // SUBI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05  // Byte 7
    };
    Runtime runtime = Runtime{program};
    runtime.start();

    std::uint64_t debug_register = runtime.debug_get_registers()[1];

    EXPECT_EQ(debug_register, 0);
}

TEST(RuntimeTests, SWAPI)
{
    std::vector<std::uint8_t> program = {
        0x00, // XORI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
        0x03, // SWAP
        0x01, // Register 1
        0x02, // Register 2
    };
    Runtime runtime = Runtime{program};
    runtime.start();

    std::uint64_t debug_register = runtime.debug_get_registers()[2];

    EXPECT_EQ(debug_register, 5);
}

TEST(RuntimeTests, SWAPI_REVERSE)
{
    std::vector<std::uint8_t> program = {
        0x00, // XORI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
        0x03, // SWAP
        0x01, // Register 1
        0x02, // Register 2
        0x03, // SWAP
        0x01, // Register 1
        0x02, // Register 2
    };
    Runtime runtime = Runtime{program};
    runtime.start();

    std::uint64_t debug_register = runtime.debug_get_registers()[2];

    EXPECT_EQ(debug_register, 0);
}

TEST(RuntimeTests, ROTR)
{
    std::vector<std::uint8_t> program = {
        0x00, // XORI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
        0x04, // ROTR
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
    };
    Runtime runtime = Runtime{program};
    runtime.start();

    std::uint64_t debug_register = runtime.debug_get_registers()[1];

    EXPECT_EQ(debug_register, 2882303761517117440);
}

TEST(RuntimeTests, ROTL)
{
    std::vector<std::uint8_t> program = {
        0x00, // XORI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
        0x05, // ROTL
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
    };
    Runtime runtime = Runtime{program};
    runtime.start();

    std::uint64_t debug_register = runtime.debug_get_registers()[1];

    EXPECT_EQ(debug_register, 160);
}

TEST(RuntimeTests, ROT_REVERSE)
{
    std::vector<std::uint8_t> program = {
        0x00, // XORI
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
        0x05, // ROTL
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
        0x04, // ROTR
        0x01, // Register 1
        0x00, // Immediate byte 0
        0x00, // Byte 1
        0x00, // Byte 2
        0x00, // Byte 3
        0x00, // Byte 4
        0x00, // Byte 5
        0x00, // Byte 6
        0x05, // Byte 7
    };
    Runtime runtime = Runtime{program};
    runtime.start();

    std::uint64_t debug_register = runtime.debug_get_registers()[1];

    EXPECT_EQ(debug_register, 5);
}