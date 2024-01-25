#include <iostream>
#include "UALdict.hpp"
#include <cassert>

int main()
{
    // 创建一个 UALdict 对象
    UALdict<std::string, int> myDict;

    // 插入键值对
    myDict.insert("one", 1);
    myDict.insert("two", 2);
    myDict.insert("three", 3);

    // 查找键值对
    std::cout << "Value for key 'two': " << myDict.find("two") << std::endl;

    // 移除键值对
    int removedValue = myDict.remove("one");
    std::cout << "Removed value for key 'one': " << removedValue << std::endl;

    // 清空字典
    myDict.clear();

    // 添加新的键值对
    myDict.insert("four", 4);

    // 测试字典大小
    assert(myDict.size() == 1);

    // 移除任意元素
    int item = myDict.removeAny();
    std::cout << "Removed any value: " << item << std::endl;

    // 测试字典是否为空
    assert(myDict.size() == 0);

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}