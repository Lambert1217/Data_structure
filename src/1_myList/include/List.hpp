#pragma once

template <class Elem>
class List
{
private:
    void operator=(const List &) {}
    List(const List &) {}

public:
    List() {}
    virtual ~List() {}
    virtual void clear() = 0;              // 清空
    virtual void insert(const Elem &) = 0; // 在当前位置插入
    virtual void append(const Elem &) = 0; // 末尾添加
    virtual Elem remove() = 0;             // 当前位置删除
    virtual Elem getValue() const = 0;     // 获取当前位置的值
    virtual void moveTostart() = 0;        // 移到头
    virtual void moveToend() = 0;          // 移到尾
    virtual void prev() = 0;               // 上一个
    virtual void next() = 0;               // 下一个
    virtual void moveToPos(int pos) = 0;   // 移到pos
    virtual int currPos() const = 0;       // 返回当前pos
    virtual int length() const = 0;        // 返回大小
};
