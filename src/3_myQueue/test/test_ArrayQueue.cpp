#include <iostream>
#include "ArrayQueue.hpp"

using namespace std;

int main()
{
    // 创建链式队列
    ArrayQueue<int> AQueue;

    // 入队
    AQueue.enqueue(1);
    AQueue.enqueue(2);
    AQueue.enqueue(3);

    // 获取队列长度并输出
    std::cout << "Queue Length: " << AQueue.length() << std::endl;

    // 输出队首元素
    std::cout << "Front Element: " << AQueue.frontValue() << std::endl;

    // 出队并输出
    while (AQueue.length() > 0)
    {
        std::cout << "Dequeue: " << AQueue.dequeue() << std::endl;
    }

    // 获取队列长度并输出
    std::cout << "Queue Length: " << AQueue.length() << std::endl;
    return 0;
}