#include <iostream>
#include <fstream>
#include <unordered_map>
#include "HuffTree.hpp"
#include "Heap.hpp"

// minHeap 比较
struct minTreeComp
{
    static bool prior(HuffTree<char> *A, HuffTree<char> *B)
    {
        return A->weight() < B->weight();
    }
};

// 读取文件并统计频率存储
void countCharacterFrequency(const std::string &filename, std::unordered_map<char, int> &frequencyMap);
// 通过各字符频率生成HuffTree
HuffTree<char> *buildHuff(HuffTree<char> **leafs, int count);
// 生成编码表
void WriteHuffcode(const std::string &filename, HuffTree<char> *hufftree);
void WriteHuffcodeHelper(HuffNode<char> *node, std::string code, std::unordered_map<char, std::string> &Huffcodes);

int main(int argc, char *argv[])
{
    // 判断参数数量
    if (argc != 3)
    {
        std::cout << "参数错误" << std::endl;
        return 1;
    }
    std::unordered_map<char, int> frequencyMap;
    // 统计频率
    countCharacterFrequency(argv[1], frequencyMap);
    // 生成叶子节点数组
    const int size = frequencyMap.size();
    HuffTree<char> **leafs = new HuffTree<char> *[size];
    int index = 0;
    for (const auto &e : frequencyMap)
    {
        leafs[index++] = new HuffTree<char>(e.first, e.second);
    }

    // 生成哈夫曼树
    HuffTree<char> *hufftree = buildHuff(leafs, size);

    // 输出编码表
    WriteHuffcode(argv[2], hufftree);

    delete[] leafs;
    return 0;
}

HuffTree<char> *buildHuff(HuffTree<char> **leafs, int count)
{
    Heap<HuffTree<char> *, minTreeComp> minheap(leafs, count, count);
    HuffTree<char> *temp1, *temp2, *temp3;
    while (minheap.size() > 1)
    {
        temp1 = minheap.removefirst();
        temp2 = minheap.removefirst();
        temp3 = new HuffTree<char>(temp1, temp2);
        minheap.insert(temp3);
    }
    return temp3;
}

void WriteHuffcode(const std::string &filename, HuffTree<char> *hufftree)
{
    // Open the file
    std::ofstream file(filename);

    // Check if the file is opened successfully
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::unordered_map<char, std::string> Huffcodes;
    std::string code;

    WriteHuffcodeHelper(hufftree->Root(), code, Huffcodes);

    for (const auto &e : Huffcodes)
    {
        file << e.first << " : " << e.second << std::endl;
    }

    file.close();
}

void WriteHuffcodeHelper(HuffNode<char> *node, std::string code, std::unordered_map<char, std::string> &Huffcodes)
{
    if (node->isLeaf())
    {
        HuffLeafNode<char> *leafNode = dynamic_cast<HuffLeafNode<char> *>(node);
        if (leafNode)
        {
            char character = leafNode->val();
            Huffcodes[character] = code;
            // Optionally, you can print the character and its Huffman code
            std::cout << "Character: " << character << ", Huffman Code: " << code << std::endl;
        }
        else
        {
            // Handle the case where dynamic_cast fails
            std::cerr << "Error: Type conversion failed for leaf node." << std::endl;
        }
    }
    else
    {
        // Recursively traverse left (append '0' to the code) and then right (append '1')
        WriteHuffcodeHelper(dynamic_cast<HuffIntlNode<char> *>(node)->left(), code + "0", Huffcodes);
        WriteHuffcodeHelper(dynamic_cast<HuffIntlNode<char> *>(node)->right(), code + "1", Huffcodes);
    }
}

void countCharacterFrequency(const std::string &filename, std::unordered_map<char, int> &frequencyMap)
{
    // Open the file
    std::ifstream file(filename);

    // Check if the file is opened successfully
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Read characters from the file and update the frequency map
    char ch;
    while (file.get(ch))
    {
        frequencyMap[ch]++;
    }

    // Close the file
    file.close();
}
