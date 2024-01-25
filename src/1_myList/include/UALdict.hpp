#pragma once
#include "Arraylist.hpp"
#include "KeyValuePair.hpp"
#include "Dictionary.hpp"

/**
 * @brief 使用无序顺序表实现字典
 *
 * @tparam Key 字典键的类型
 * @tparam Elem 字典值的类型
 */
template <typename Key, typename Elem>
class UALdict : public Dictionary<Key, Elem>
{
private:
    Arraylist<KeyValuePair<Key, Elem>> *list; // 无序顺序表的指针，存储键值对

public:
    /**
     * @brief 构造函数
     *
     * @param size 初始化无序顺序表的大小，默认为10
     */
    UALdict(int size = 10)
    {
        list = new Arraylist<KeyValuePair<Key, Elem>>(size);
    }

    /**
     * @brief 析构函数
     */
    ~UALdict() { delete list; }

    /**
     * @brief 清空字典中的所有键值对
     */
    void clear() override
    {
        list->clear();
    }

    /**
     * @brief 向字典中插入键值对
     *
     * @param k 键
     * @param e 值
     */
    void insert(const Key &k, const Elem &e) override
    {
        KeyValuePair<Key, Elem> temp(k, e);
        list->append(temp);
    }

    /**
     * @brief 根据键移除字典中的键值对
     *
     * @param k 要移除的键
     * @return Elem 返回被移除的值
     */
    Elem remove(const Key &k) override
    {
        Elem item = find(k);
        if (item != NULL)
        {
            list->remove(); // find时把curr移动到了目标处，直接删除即可
        }
        return item;
    }

    /**
     * @brief 移除字典中的任意键值对
     *
     * @return Elem 返回被移除的值
     * @throw std::out_of_range 若字典为空
     */
    Elem removeAny() override
    {
        if (size() == 0)
        {
            throw std::out_of_range("UALdict is empty.");
        }
        list->moveToend();
        list->prev();
        KeyValuePair<Key, Elem> temp = list->remove();
        return temp.Value();
    }

    /**
     * @brief 根据键查找字典中的值
     *
     * @param k 要查找的键
     * @return Elem 返回找到的值，若未找到返回NULL
     */
    Elem find(const Key &k) const override
    {
        for (list->moveTostart(); list->currPos() < list->length(); list->next())
        {
            KeyValuePair<Key, Elem> temp = list->getValue();
            if (k == temp.key())
            {
                return temp.Value();
            }
        }
        return NULL;
    }

    /**
     * @brief 获取字典中键值对的数量
     *
     * @return int 返回字典中键值对的数量
     */
    int size() const override
    {
        return list->length();
    }
};
