#pragma once

#include <stdexcept>
#include "Queue.hpp"

/**
 * @brief 顺序队列   循环
 * 本次实现方法：
 *      设置队列大小为 maxSize+1 , front 指向队首元素 , rear 指向队尾元素的后一个
 *      空满判断条件： if((rear+1)%maxSize == front) 空;   if((rear+2)%maxSize == front) 满;
 * @tparam Elem
 */
template <typename Elem>
class ArrayQueue : public Queue<Elem>
{
private:
    int maxSize;
    int front;
    int rear;
    Elem *listArray;

public:
    ArrayQueue(int size = 10)
    {
        maxSize = size + 1;
        rear = 0;
        front = 1;
        listArray = new Elem[maxSize];
    }
    ~ArrayQueue() { delete[] listArray; }

    void clear() override
    {
        rear = 0;
        front = 1;
    }

    void enqueue(const Elem &item) override
    {
        if ((rear + 2) % maxSize == front)
        {
            throw std::out_of_range("ArrayQueue is full.");
        }
        else
        {
            rear = (rear + 1) % maxSize;
            listArray[rear] = item;
        }
    }

    Elem dequeue() override
    {
        if ((rear + 1) % maxSize == front)
        {
            throw std::out_of_range("ArrayQueue is empty.");
        }
        else
        {
            Elem item = listArray[front];
            front = (front + 1) % maxSize;
            return item;
        }
    }

    const Elem &frontValue() const override
    {
        if ((rear + 1) % maxSize == front)
        {
            throw std::out_of_range("ArrayQueue is empty.");
        }
        else
        {
            return listArray[front];
        }
    }

    int length() const override
    {
        return ((maxSize + rear) - front + 1) % maxSize;
    }
};