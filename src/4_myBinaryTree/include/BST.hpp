#pragma once

#include "BSTNode.hpp"
#include "Dictionary.hpp"
#include <iostream>

template <typename Key, typename E>
class BST : public Dictionary<Key, E>
{
private:
    BSTNode<Key, E> *root;
    int nodecount;

    // 私有帮助函数
    void clearhelp(BSTNode<Key, E> *);
    BSTNode<Key, E> *inserthelp(BSTNode<Key, E> *, const Key &, const E &);
    BSTNode<Key, E> *deletemin(BSTNode<Key, E> *);
    BSTNode<Key, E> *getmin(BSTNode<Key, E> *);
    BSTNode<Key, E> *removehelp(BSTNode<Key, E> *, const Key &);
    E findhelp(BSTNode<Key, E> *, const Key &) const;
    void printhelp(BSTNode<Key, E> *, int) const;

public:
    BST()
    {
        root = nullptr;
        nodecount = 0;
    }
    ~BST() { clearhelp(root); }
    void clear()
    {
        clearhelp(root);
        root = nullptr;
        nodecount = 0;
    }
    void insert(const Key &k, const E &e)
    {
        root = inserthelp(root, k, e);
        nodecount++;
    }
    E remove(const Key &k)
    {
        E temp = findhelp(root, k);
        if (temp != E())
        {
            root = removehelp(root, k);
            nodecount--;
        }
        return temp;
    }
    E removeAny()
    {
        if (root != nullptr)
        {
            E temp = root->element();
            root = removehelp(root, root->key());
            nodecount--;
            return temp;
        }
        return E();
    }
    E find(const Key &k) const
    {
        return findhelp(root, k);
    }
    int size() const
    {
        return nodecount;
    }

    void print() const
    {
        if (root == nullptr)
        {
            std::cout << "BST is empty." << std::endl;
        }
        else
        {
            printhelp(root, 0);
        }
    }
};

template <typename Key, typename E>
inline void BST<Key, E>::printhelp(BSTNode<Key, E> *root, int level) const
{
    using namespace std;
    if (root == nullptr)
    {
        return;
    }
    printhelp(root->left(), level + 1);
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }
    cout << root->key() << endl;
    printhelp(root->right(), level + 1);
}

/**
 * @brief 子节点必须先于父节点释放，所以采用后序遍历
 *
 * @tparam Key
 * @tparam E
 * @param root
 */
template <typename Key, typename E>
inline void BST<Key, E>::clearhelp(BSTNode<Key, E> *root)
{
    if (root == nullptr)
    {
        return;
    }
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}

/**
 * @brief 递归，多次设置子树的指针值，但是逻辑上只有路径上最后一个节点的值变化，这些额外赋值是值得的；
 *     插入时，BST的结构和插入顺序有关系，当排好序之后插入，就会形成一条链；
 *     理论上，BST的高度越小越好，可以使得BST操作的均摊代价减少
 * @tparam Key
 * @tparam E
 * @return BSTNode<Key, E>*
 */
template <typename Key, typename E>
inline BSTNode<Key, E> *BST<Key, E>::inserthelp(BSTNode<Key, E> *root, const Key &k, const E &e)
{
    if (root == nullptr)
    {
        return new BSTNode<Key, E>(k, e, nullptr, nullptr);
    }
    if (k < root->key())
    {
        root->setLeft(inserthelp(root->left(), k, e));
    }
    else
    {
        root->setRight(inserthelp(root->right(), k, e));
    }
    return root;
}

/**
 * @brief 最小值一定没有左子节点，只需要一直向左，知道找到最小，然后用其右子节点替换之
 *
 * @tparam Key
 * @tparam E
 * @param rt
 * @return BSTNode<Key, E>*
 */
template <typename Key, typename E>
inline BSTNode<Key, E> *BST<Key, E>::deletemin(BSTNode<Key, E> *root)
{
    if (root->left() == nullptr)
    {
        return root->right();
    }
    else
    {
        root->setLeft(deletemin(root->left()));
        return root;
    }
}

template <typename Key, typename E>
inline BSTNode<Key, E> *BST<Key, E>::getmin(BSTNode<Key, E> *root)
{
    if (root->left() == nullptr)
    {
        return root;
    }
    else
    {
        return getmin(root->left());
    }
}

/**
 * @brief 找到要删除的节点后, 删除并用其右子树中的最小值替换之
 *
 * @tparam Key
 * @tparam E
 * @param root
 * @param k
 * @return BSTNode<Key, E>*
 */
template <typename Key, typename E>
inline BSTNode<Key, E> *BST<Key, E>::removehelp(BSTNode<Key, E> *root, const Key &k)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (k < root->key())
    {
        root->setLeft(removehelp(root->left(), k));
    }
    else if (k > root->key())
    {
        root->setRight(removehelp(root->right(), k));
    }
    else
    {
        BSTNode<Key, E> *temp = root;
        if (temp->left() == nullptr)
        {
            root = root->right();
            delete temp;
        }
        else if (temp->right() == nullptr)
        {
            root = root->left();
            delete temp;
        }
        else
        {
            temp = getmin(root->right());
            root->setElement(temp->element());
            root->setKey(temp->key());
            root->setRight(deletemin(root->right()));
            delete temp;
        }
    }
    return root;
}

/**
 * @brief 递归查找,小于——>左子树    大于——>右子树    等于——>返回
 *
 * @tparam Key
 * @tparam E
 * @param root
 * @param k
 * @return E
 */
template <typename Key, typename E>
inline E BST<Key, E>::findhelp(BSTNode<Key, E> *root, const Key &k) const
{
    if (root == nullptr)
    {
        return E();
    }
    if (k < root->key())
    {
        return findhelp(root->left(), k);
    }
    else if (k > root->key())
    {
        return findhelp(root->right(), k);
    }
    else
    {
        return root->element();
    }
}
