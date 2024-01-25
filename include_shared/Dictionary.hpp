#pragma once

/**
 * @brief  字典  接口
 *
 * @tparam Key
 * @tparam Elem
 */
template <typename Key, typename Elem>
class Dictionary
{
private:
    void operator=(const Dictionary &) {}
    Dictionary(const Dictionary &) {}

public:
    Dictionary() {}
    virtual ~Dictionary() {}

    virtual void clear() = 0;
    virtual void insert(const Key &k, const Elem &e) = 0;
    virtual Elem remove(const Key &k) = 0;
    virtual Elem removeAny() = 0; // 删除任意一个元素，可以用于遍历，遍历结束字典变成空
    virtual Elem find(const Key &k) const = 0;
    virtual int size() const = 0;
};
