#pragma once

/**
 * @brief  二叉树节点接口类
 *
 * @tparam Elem
 */
template <typename Elem>
class BinNode
{
public:
    virtual ~BinNode() {}
    virtual Elem &element() = 0;
    virtual void setElement(const Elem &) = 0;
    virtual BinNode *left() const = 0;
    virtual void setLeft(BinNode *) = 0;
    virtual BinNode *right() const = 0;
    virtual void setRight(BinNode *) = 0;
    virtual bool isLeaf() = 0;
};