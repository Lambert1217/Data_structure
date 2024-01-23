#include <iostream>
#include "LinkStack.hpp"

/**
 * @brief 使用链式栈实现递归求解 n！
 * 超出 unsigned long long 范围后，结果为0
 * @param n
 * @return unsigned long long
 */
unsigned long long fact(unsigned int n)
{
    LinkStack<int> stack;
    unsigned long long result = 1;
    while (n > 1)
    {
        stack.push(n--);
    }
    while (stack.length())
    {
        result *= stack.pop();
    }
    return result;
}

int main()
{

    std::cout << fact(70) << std::endl;
    return 0;
}