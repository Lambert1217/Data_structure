#pragma once

#include "HuffNode.hpp"

template <typename E>
class HuffTree
{
private:
    HuffNode<E> *root;

public:
    HuffTree(const E &val, int freq) { root = new HuffLeafNode<E>(val, freq); }
    HuffTree(HuffTree<E> *l, HuffTree<E> *r)
    {
        root = new HuffIntlNode<E>(l->Root(), r->Root());
    }
    ~HuffTree() { delete root; }
    HuffNode<E> *Root() { return root; }
    int weight() { return root->weight(); }
};