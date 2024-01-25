#pragma once

/**
 * @brief 队列接口
 *
 * @tparam Elem
 */
template <typename Elem>
class Queue
{
private:
    void operator=(const Queue &) {}
    Queue(const Queue &) {}

public:
    Queue() {}
    virtual ~Queue() {}

    virtual void clear() = 0;
    virtual void enqueue(const Elem &) = 0;     // 入队
    virtual Elem dequeue() = 0;                 // 出队
    virtual const Elem &frontValue() const = 0; // 返回队首元素
    virtual int length() const = 0;
};