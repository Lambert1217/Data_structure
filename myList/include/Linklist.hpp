#pragma once

#include <stdexcept>
#include "List.hpp"

template <class Elem>
class Linklist : public List<Elem>
{
private:
public:
    Arraylist()
    {
    }
    ~Arraylist() {}

    // 清空
    void clear() override
    {
    }

    // 当前位置插入 O(n)
    void insert(const Elem &item) override
    {
    }

    // 末尾插入 O(1)
    void append(const Elem &item) override
    {
    }

    // 当前位置删除 O(n)
    Elem remove() override
    {
    }

    // 获取当前位置的值  O(1)
    Elem getValue() const override
    {
    }

    void moveTostart() override {} // 移到头
    void moveToend() override {}   // 移到尾
    // 上一个
    void prev() override
    {
    }
    // 下一个
    void next() override
    {
    }
    // 移到pos
    void moveToPos(int pos) override
    {
    }

    int currPos() const override {} // 返回当前pos
    int length() const override {}  // 返回大小
};