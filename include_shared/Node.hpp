#pragma once

/**
 * @brief
 * 单链表节点
 * 支持一种内存管理技术————自由列表
 * 可以提高内存分配和释放的效率，尤其在频繁创建和销毁节点的情况下。
 * @tparam Elem
 */
template <class Elem>
class Node
{

private:
    // 指向 freelist 头
    static Node<Elem> *freelist;

public:
    Elem element;
    Node<Elem> *next;
    Node(const Elem &item, Node<Elem> *_next = nullptr)
    {
        element = item;
        next = _next;
    }
    Node(Node<Elem> *_next = nullptr)
    {
        next = _next;
    }
    // 重载 new delete
    void *operator new(size_t)
    {
        if (freelist == nullptr)
        {
            return ::new Node; // 使用全局 ::new 运算符分配新的节点。
        }
        Node<Elem> *temp = freelist;
        freelist = freelist->next;
        return temp;
    }

    void operator delete(void *ptr)
    {
        ((Node<Elem> *)ptr)->next = freelist;
        freelist = (Node<Elem> *)ptr;
    }
};

// freelist 头指针初始化
template <class Elem>
Node<Elem> *Node<Elem>::freelist = nullptr;