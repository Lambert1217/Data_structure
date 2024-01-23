#pragma once

#include <stdexcept>
#include "Stack.hpp"

template <typename Elem>
class ArrayStack : public Stack<Elem>
{
private:
    int maxSize;
    int top;
    Elem *listArray;

public:
    ArrayStack(int size = 10)
    {
        maxSize = size;
        top = 0;
        listArray = new Elem[maxSize];
    }
    ~ArrayStack() { delete[] listArray; }

    void clear() override
    {
        top = 0;
    }

    void push(const Elem &item) override
    {
        if (top < maxSize)
        {
            listArray[top++] = item;
        }
        else
        {
            throw std::out_of_range("ArrayStack is full.");
        }
    }

    Elem pop() override
    {
        if (top == 0)
        {
            throw std::out_of_range("ArrayStack is empty.");
        }
        else
        {
            return listArray[--top];
        }
    }

    const Elem &topValue() const override
    {
        if (top == 0)
        {
            throw std::out_of_range("ArrayStack is empty.");
        }
        else
        {
            return listArray[top - 1];
        }
    }

    int length() const override
    {
        return top;
    }
};