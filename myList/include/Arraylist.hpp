#pragma once

#include <stdexcept>
#include "List.hpp"

template <class Elem>
class Arraylist : public List<Elem>
{
private:
    int maxSize;
    int ListSize;
    int curr;
    Elem *ListArray;

public:
    Arraylist(int size)
    {
        maxSize = size;
        ListSize = curr = 0;
        ListArray = new Elem[maxSize];
    }
    ~Arraylist() { delete[] ListArray; }

    // 清空
    void clear() override
    {
        delete[] ListArray;
        ListArray = nullptr;
        ListSize = curr = 0;
        ListArray = new Elem[maxSize];
    }

    // 当前位置插入 O(n)
    void insert(const Elem &item) override
    {
        if (ListSize >= maxSize)
        {
            throw std::out_of_range("Arraylist is full");
        }
        for (int i = ListSize; i > curr; i--)
        {
            ListArray[i] = ListArray[i - 1];
        }
        ListArray[curr] = item;
        ListSize++;
    }

    // 末尾插入 O(1)
    void append(const Elem &item) override
    {
        if (ListSize >= maxSize)
        {
            throw std::out_of_range("Arraylist is full");
        }
        ListArray[ListSize] = item;
        ListSize++;
    }

    // 当前位置删除 O(n)
    Elem remove() override
    {
        if (ListSize == 0)
        {
            throw std::out_of_range("No element");
        }
        Elem item = ListArray[curr];
        for (int i = curr; i < ListSize - 1; i++)
        {
            ListArray[i] = ListArray[i + 1];
        }
        ListSize--;
        return item;
    }

    // 获取当前位置的值  O(1)
    Elem getValue() const override
    {
        return ListArray[curr];
    }

    void moveTostart() override { curr = 0; }          // 移到头
    void moveToend() override { curr = ListSize - 1; } // 移到尾
    // 上一个
    void prev() override
    {
        if (curr > 0)
            curr--;
    }
    // 下一个
    void next() override
    {
        if (curr < ListSize - 1)
            curr++;
    }
    // 移到pos
    void moveToPos(int pos) override
    {
        if (pos >= 0 && pos < ListSize)
        {
            curr = pos;
        }
        else
        {
            throw std::out_of_range("Invalid position (Pos)");
        }
    }

    int currPos() const override { return curr; }    // 返回当前pos
    int length() const override { return ListSize; } // 返回大小

    // 重载[]
    Elem operator[](int index) const override
    {
        if (index >= 0 && index < ListSize)
        {
            return ListArray[index];
        }
        else
        {
            throw std::out_of_range("Invalid index");
        }
    }
};