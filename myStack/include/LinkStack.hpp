#pragma once

#include <stdexcept>
#include "Stack.hpp"
#include "Node.hpp"

template <typename Elem>
class LinkStack : public Stack<Elem>
{
private:
    Node<Elem> *top;
    int size;

public:
    LinkStack()
    {
        size = 0;
        top = nullptr;
    }
    ~LinkStack()
    {
        clear();
    }

    void clear() override
    {
        while (top != nullptr)
        {
            Node<Elem> *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    void push(const Elem &item) override
    {
        top = new Node<Elem>(item, top);
        size++;
    }

    Elem pop() override
    {
        if (top == nullptr)
        {
            throw std::out_of_range("LinkStack is empty.");
        }
        else
        {
            Node<Elem> *temp = top;
            Elem item = temp->element;
            top = top->next;
            delete temp;
            size--;
            return item;
        }
    }

    const Elem &topValue() const override
    {
        if (top == nullptr)
        {
            throw std::out_of_range("LinkStack is empty.");
        }
        else
        {
            return top->element;
        }
    }

    int length() const override { return size; }
};