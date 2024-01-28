# 二叉树

## 文件介绍

**./include**

- BSTNode.hpp 二叉检索树节点类
- BST.hpp 二叉检索树
- heap.hpp 堆（数组实现）

**./test**

- 测试

## BST 复杂度分析

- find，insert，remove 算法时间复杂度取决于对应的节点的深度。（一次操作）如果二叉树形成一条链，那么就是最差情况 O(n)；平均是 O(logn)。
- 构建 BST 平均 O(n^2) O(nlogn)

## 复杂度分析

- 堆是完全二叉树，高度最小。因此每次插入最差 O(logn)
- 构建 最差 O(n)
- removefirst 平均、最差 O(logn)
