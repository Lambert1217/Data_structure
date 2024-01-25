#include <iostream>
#include "LinkQueue.hpp"

int main()
{
    // 创建链式队列
    LinkQueue<int> LQueue;

    // 入队
    LQueue.enqueue(1);
    LQueue.enqueue(2);
    LQueue.enqueue(3);

    // 获取队列长度并输出
    std::cout << "Queue Length: " << LQueue.length() << std::endl;

    // 输出队首元素
    std::cout << "Front Element: " << LQueue.frontValue() << std::endl;

    // 出队并输出
    while (LQueue.length() > 0)
    {
        std::cout << "Dequeue: " << LQueue.dequeue() << std::endl;
    }

    // 获取队列长度并输出
    std::cout << "Queue Length: " << LQueue.length() << std::endl;

    return 0;
}
