#include <cstdint>
#include <deque>

class Stack
{
  private:
    std::deque<std::uint64_t> stack{};

  public:
    void push_stack(std::uint64_t number);
    std::uint64_t pop_stack();
    std::size_t size();
};
