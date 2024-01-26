#pragma once

#include "BinNode.hpp"

/**
 * @brief 二叉检索树节点类
 *
 * @tparam Key
 * @tparam Elem
 */
template <typename Key, typename Elem>
class BSTNode : public BinNode<Elem>
{
private:
    Key k;
    Elem e;
    BSTNode *lc;
    BSTNode *rc;

public:
    BSTNode() { lc = rc = nullptr; }
    BSTNode(Key key, Elem it, BSTNode *l = nullptr, BSTNode *r = nullptr)
    {
        k = key;
        e = it;
        lc = l;
        rc = r;
    }
    ~BSTNode() {}

    Elem &element() { return e; }
    void setElement(const Elem &it) { e = it; }
    Key &key() { return k; }
    void setKey(const Key &key) { k = key; }

    BSTNode *left() const { return lc; }
    void setLeft(BinNode<Elem> *l) { lc = (BSTNode *)l; }
    BSTNode *right() const { return rc; }
    void setRight(BinNode<Elem> *r) { rc = (BSTNode *)r; }

    bool isLeaf() { return (lc == nullptr) && (rc == nullptr); }
};