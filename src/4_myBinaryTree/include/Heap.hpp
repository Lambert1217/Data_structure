#pragma once

#include <stdexcept>

template <typename Elem, typename Comp>
class Heap
{
private:
    Elem *_heap;
    int maxsize;
    int n;

    // 私有的 swap 函数
    void swap(Elem *arr, int i, int j)
    {
        Elem temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // 分支节点下沉
    void siftdown(int pos)
    {
        while (!isLeaf(pos))
        {
            int j = leftchild(pos);
            int rc = rightchild(pos);
            if ((rc < n) && Comp::prior(_heap[rc], _heap[j]))
            {
                j = rc;
            }
            if (Comp::prior(_heap[pos], _heap[j]))
            {
                return;
            }
            swap(_heap, pos, j);
            pos = j;
        }
    }

public:
    Heap(Elem *h, int num, int max)
    {
        if (num > max)
        {
            throw std::invalid_argument("Number of elements exceeds the maximum capacity.");
        }

        _heap = h;
        n = num;
        maxsize = max;
        buildHeap();
    }

    int size() const { return n; }
    bool isLeaf(int pos) const { return (pos >= n / 2) && (pos < n); }
    int leftchild(int pos) const { return 2 * pos + 1; }
    int rightchild(int pos) const { return 2 * pos + 2; }
    int parent(int pos) const { return (pos - 1) / 2; }
    void buildHeap()
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            siftdown(i);
        }
    }
    void insert(const Elem &it)
    {
        if (n < maxsize)
        {
            int curr = n++;
            _heap[curr] = it;
            // 上浮
            while (curr != 0 && Comp::prior(_heap[curr], _heap[parent(curr)]))
            {
                swap(_heap, curr, parent(curr));
                curr = parent(curr);
            }
            return;
        }
        throw std::out_of_range("Heap is full.");
    }

    Elem removefirst()
    {
        if (n <= 0)
        {
            throw std::out_of_range("Heap is empty");
        }
        swap(_heap, 0, --n);
        if (n != 0)
        {
            siftdown(0);
        }
        return _heap[n];
    }

    Elem remove(int pos)
    {
        if (pos >= 0 && pos < n)
        {
            if (pos == (n - 1))
            {
                n--;
            }
            else
            {
                swap(_heap, pos, --n);
                while ((pos != 0) && Comp::prior(_heap[pos], _heap[parent(pos)]))
                {
                    swap(_heap, pos, parent(pos));
                    pos = parent(pos);
                }
                if (n != 0)
                {
                    siftdown(pos);
                }
            }
            return _heap[n];
        }
        throw std::out_of_range("Bad position");
    }
};