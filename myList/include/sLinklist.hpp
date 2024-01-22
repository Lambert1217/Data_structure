#pragma once

#include <stdexcept>
#include "List.hpp"
#include "Node.hpp"

/**
 * @brief
 * 单链表
 * @tparam Elem
 */
template <class Elem>
class sLinklist : public List<Elem>
{
private:
    Node<Elem> *head;
    Node<Elem> *tail;
    Node<Elem> *curr;
    int count;

    void init() // 初始化  头节点
    {
        head = tail = curr = new Node<Elem>();
        count = 0;
    }

    void removeAll() // 释放所有内存
    {
        while (head != nullptr)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    sLinklist() { init(); }
    ~sLinklist() { removeAll(); }

    // 清空
    void clear() override
    {
        removeAll();
        init();
    }

    // 当前位置插入 O(1)         1 2 3(curr) 4  -->  1 2 3(curr) 5(insert) 4
    void insert(const Elem &item) override
    {
        curr->next = new Node<Elem>(item, curr->next);
        if (curr == tail)
        {
            tail = curr->next;
        }
        count++;
    }

    // 末尾插入 O(1)
    void append(const Elem &item) override
    {
        tail = tail->next = new Node<Elem>(item, nullptr);
        count++;
    }

    // 当前位置删除 O(1)       1 2 3(curr) 4 5 -->  1 2 3(curr) 5
    Elem remove() override
    {
        if (curr->next == nullptr)
        {
            throw std::invalid_argument("Remove failed.");
        }
        // 记录
        Node<Elem> *node = curr->next;
        Elem item = node->element;
        // 删除
        curr->next = node->next;
        if (node == tail)
        {
            tail = curr;
        }
        delete node;
        count--;
        return item;
    }

    // 获取当前位置的值  O(1)
    Elem getValue() const override
    {
        if (curr->next == nullptr)
        {
            throw std::invalid_argument("getValue failed.");
        }
        return curr->next->element;
    }

    void moveTostart() override { curr = head; } // 移到头   O(1)
    void moveToend() override { curr = tail; }   // 移到尾   O(1)
    // 上一个O(n)
    void prev() override
    {
        if (curr == head)
        {
            return;
        }
        Node<Elem> *temp = head;
        while (temp->next != curr)
        {
            temp = temp->next;
        }
        curr = temp;
    }
    // 下一个
    void next() override
    {
        if (curr != tail)
        {
            curr = curr->next;
        }
    }
    // 移到pos  O(n)
    void moveToPos(int pos) override
    {
        if (pos < 0 || pos > count)
        {
            throw std::out_of_range("Invalid position(Pos)");
        }
        curr = head;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        }
    }

    // 返回当前pos    O(n)
    int currPos() const override
    {
        int i = 0;
        Node<Elem> *temp = head;
        while (temp != curr)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
    int length() const override { return count; } // 返回大小

    // 重载[]  O(n)
    Elem operator[](int index) const override
    {
        if (index >= 0 && index < count)
        {
            Node<Elem> *temp = head;
            int i = 0;
            while (i != index)
            {
                temp = temp->next;
                i++;
            }
            return temp->next->element;
        }
        else
        {
            throw std::out_of_range("Invalid index");
        }
    }
};