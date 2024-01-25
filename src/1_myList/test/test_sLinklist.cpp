#include <iostream>
#include "sLinklist.hpp"

/**
 * @brief
 * 打印ArrayList
 * @tparam Elem
 * @param Arraylist<Elem> &
 */
template <class Elem>
void show_Alist(sLinklist<Elem> &_slList)
{
    int curr = _slList.currPos();
    _slList.moveTostart();
    while (1)
    {
        std::cout << _slList.getValue() << std::endl;
        if (_slList.currPos() + 1 == _slList.length())
        {
            break;
        }
        _slList.next();
    }
    _slList.moveToPos(curr);
}

int main()
{
    sLinklist<int> slList;
    slList.append(41);
    slList.append(51);
    slList.insert(31);
    slList.insert(21);
    slList.insert(11);
    std::cout << "刚赋值：" << std::endl;
    show_Alist(slList);
    slList.moveToPos(1);
    int x = slList.remove();
    std::cout << "删除 slList[1] = " << x << std::endl;
    show_Alist(slList);
    slList.append(666);
    std::cout << "append(666)" << std::endl;
    show_Alist(slList);
    return 0;
}