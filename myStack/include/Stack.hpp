#pragma once

template <typename Elem>
class Stack
{
private:
    // 保护 operator= 和 拷贝构造
    void operator=(const Stack &) {}
    Stack(const Stack &) {}

public:
    Stack(){};
    virtual ~Stack(){};
    virtual void clear() = 0;
    virtual void push(const Elem &) = 0;
    virtual Elem pop() = 0;
    virtual const Elem &topValue() const = 0;
    virtual int length() const = 0;
};
