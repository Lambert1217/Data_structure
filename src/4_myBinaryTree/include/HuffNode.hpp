#pragma once

template <typename E>
class HuffNode
{
public:
    virtual ~HuffNode() {}
    virtual int weight() = 0;
    virtual bool isLeaf() = 0;
};

template <typename E>
class HuffLeafNode : public HuffNode<E>
{
private:
    E item;
    int w;

public:
    HuffLeafNode(const E &it, int freq)
    {
        item = it;
        w = freq;
    }
    int weight() { return w; }
    bool isLeaf() { return true; }
    E val() { return item; }
};

template <typename E>
class HuffIntlNode : public HuffNode<E>
{
private:
    HuffNode<E> *lc;
    HuffNode<E> *rc;
    int w;

public:
    HuffIntlNode(HuffNode<E> *l, HuffNode<E> *r)
    {
        lc = l;
        rc = r;
        w = l->weight() + r->weight();
    }
    int weight() { return w; }
    bool isLeaf() { return false; }
    HuffNode<E> *left() const { return lc; }
    HuffNode<E> *right() const { return rc; }
    void setLeft(HuffNode<E> *l) { lc = (HuffNode<E> *)l; }
    void setRight(HuffNode<E> *r) { rc = (HuffNode<E> *)r; }
};