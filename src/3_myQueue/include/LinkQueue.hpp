#pragma once

#include "Node.hpp"
#include "Queue.hpp"

/**
 * @brief 链式队列
 *
 * @tparam Elem
 */
template <typename Elem>
class LinkQueue : public Queue<Elem>
{
private:
    Node<Elem> *front; // 队首指针
    Node<Elem> *rear;  // 队尾指针
    int size;          // 队列长度

    bool isEmpty() const
    {
        return size == 0;
    }

public:
    LinkQueue() : front(nullptr), rear(nullptr), size(0) {}

    ~LinkQueue() override
    {
        clear();
    }

    void clear() override
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    void enqueue(const Elem &item) override
    {
        Node<Elem> *newNode = new Node<Elem>(item);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    Elem dequeue() override
    {
        if (isEmpty())
        {
            // 队列为空，处理异常或返回一个默认值
            throw std::out_of_range("Queue is empty");
        }

        Elem frontData = front->element;
        Node<Elem> *temp = front;
        front = front->next;
        delete temp;
        size--;

        if (isEmpty())
        {
            rear = nullptr; // 如果队列为空，重置rear指针
        }

        return frontData;
    }

    const Elem &frontValue() const override
    {
        if (isEmpty())
        {
            // 队列为空，处理异常或返回一个默认值
            throw std::out_of_range("Queue is empty");
        }
        return front->element;
    }

    int length() const override
    {
        return size;
    }
};
