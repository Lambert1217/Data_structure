#include <iostream>
#include "HuffTree.hpp"

int main()
{
    // 创建一些叶子节点
    HuffTree<char> leafA('A', 5);
    HuffTree<char> leafB('B', 7);
    HuffTree<char> leafC('C', 2);

    // 创建一个内部节点，将两个叶子节点合并
    HuffTree<char> internalNode(&leafA, &leafB);

    // 创建根节点，将内部节点和另一个叶子节点合并
    HuffTree<char> huffmanTree(&internalNode, &leafC);

    // 输出Huffman树的权重
    std::cout << "Huffman树的权重: " << huffmanTree.weight() << std::endl;

    return 0;
}
