#include <lethe/interpreter/memory/stack.hpp>

void Stack::push_stack(std::uint64_t number)
{
    stack.push_back(number);
}

std::uint64_t Stack::pop_stack()
{
    std::uint64_t back = stack.back();
    stack.pop_back();

    return back;
}

std::size_t Stack::size()
{
    return stack.size();
}