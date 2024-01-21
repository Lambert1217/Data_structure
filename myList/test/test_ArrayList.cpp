#include <iostream>
#include "Arraylist.hpp"

/**
 * @brief
 * 打印ArrayList
 * @tparam Elem
 * @param Arraylist<Elem> &
 */
template <class Elem>
void show_Alist(Arraylist<Elem> &_Alist)
{
    int curr = _Alist.currPos();
    _Alist.moveTostart();
    while (1)
    {
        std::cout << _Alist.getValue() << std::endl;
        if (_Alist.currPos() + 1 == _Alist.length())
        {
            break;
        }
        _Alist.next();
    }
    _Alist.moveToPos(curr);
}

int main()
{
    Arraylist<int> Alist(5);
    Alist.append(41);
    Alist.append(51);
    Alist.insert(31);
    Alist.insert(21);
    Alist.insert(11);
    std::cout << "刚赋值：" << std::endl;
    show_Alist(Alist);
    Alist.moveToPos(1);
    Alist.remove();
    std::cout << "删除 Alist[1]" << std::endl;
    show_Alist(Alist);
    return 0;
}