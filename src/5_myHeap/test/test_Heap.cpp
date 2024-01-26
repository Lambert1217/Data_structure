#include <iostream>
#include "Heap.hpp"

// 示例比较器类，用于比较整数的大小
struct IntComparator_max
{
    static bool prior(int a, int b)
    {
        return a > b; // 大顶堆
    }
};

struct IntComparator_min
{
    static bool prior(int a, int b)
    {
        return a < b; // 小顶堆
    }
};

int main()
{
    const int maxSize = 10;
    int heapArray[maxSize] = {4, 10, 3, 5, 1, 8, 7, 2, 9, 6};

    // 创建大顶堆
    Heap<int, IntComparator_max> maxHeapInstance(heapArray, 8, maxSize);

    // 输出大顶堆元素
    std::cout << "Max Heap elements: ";
    for (int i = 0; i < maxHeapInstance.size(); ++i)
    {
        std::cout << heapArray[i] << " ";
    }
    std::cout << "\n";

    // 插入新元素到大顶堆
    maxHeapInstance.insert(11);

    // 输出插入后的大顶堆元素
    std::cout << "Max Heap elements after insertion: ";
    for (int i = 0; i < maxHeapInstance.size(); ++i)
    {
        std::cout << heapArray[i] << " ";
    }
    std::cout << "\n";

    // 移除大顶堆顶元素
    int removedElementMaxHeap = maxHeapInstance.removefirst();
    std::cout << "Removed element from Max Heap: " << removedElementMaxHeap << "\n";

    // 输出移除大顶堆顶元素后的元素
    std::cout << "Max Heap elements after removal: ";
    for (int i = 0; i < maxHeapInstance.size(); ++i)
    {
        std::cout << heapArray[i] << " ";
    }
    std::cout << "\n";

    // 创建小顶堆
    Heap<int, IntComparator_min>
        minHeapInstance(heapArray, 8, maxSize);

    // 输出小顶堆元素
    std::cout << "Min Heap elements: ";
    for (int i = 0; i < minHeapInstance.size(); ++i)
    {
        std::cout << heapArray[i] << " ";
    }
    std::cout << "\n";

    // 插入新元素到小顶堆
    minHeapInstance.insert(0);

    // 输出插入后的小顶堆元素
    std::cout << "Min Heap elements after insertion: ";
    for (int i = 0; i < minHeapInstance.size(); ++i)
    {
        std::cout << heapArray[i] << " ";
    }
    std::cout << "\n";

    // 移除小顶堆顶元素
    int removedElementMinHeap = minHeapInstance.removefirst();
    std::cout << "Removed element from Min Heap: " << removedElementMinHeap << "\n";

    // 输出移除小顶堆顶元素后的元素
    std::cout << "Min Heap elements after removal: ";
    for (int i = 0; i < minHeapInstance.size(); ++i)
    {
        std::cout << heapArray[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
