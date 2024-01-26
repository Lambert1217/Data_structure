#include <iostream>
#include "BSTNode.hpp"

int main()
{
    // 创建一些节点进行测试
    BSTNode<int, std::string> *node1 = new BSTNode<int, std::string>(10, "Node 10");
    BSTNode<int, std::string> *node2 = new BSTNode<int, std::string>(5, "Node 5");
    BSTNode<int, std::string> *node3 = new BSTNode<int, std::string>(15, "Node 15");

    // 设置节点的左右子节点
    node1->setLeft(node2);
    node1->setRight(node3);

    // 输出节点信息
    std::cout << "Node 1 - Key: " << node1->key() << ", Element: " << node1->element() << std::endl;
    std::cout << "Node 2 - Key: " << node1->left()->key() << ", Element: " << node1->left()->element() << std::endl;
    std::cout << "Node 3 - Key: " << node1->right()->key() << ", Element: " << node1->right()->element() << std::endl;

    // 检查是否为叶子节点
    std::cout << "Node 1 is a leaf: " << (node1->isLeaf() ? "Yes" : "No") << std::endl;
    std::cout << "Node 2 is a leaf: " << (node2->isLeaf() ? "Yes" : "No") << std::endl;
    std::cout << "Node 3 is a leaf: " << (node3->isLeaf() ? "Yes" : "No") << std::endl;

    // 释放动态分配的内存
    delete node1;
    delete node2;
    delete node3;

    return 0;
}
