# 二叉树

## 文件介绍

**./include**

- BSTNode.hpp 二叉检索树节点类
- BST.hpp 二叉检索树

**./test**

- 测试

**BST 复杂度分析**

- find，insert，remove 算法时间复杂度取决于对应的节点的深度。（一次操作）如果二叉树形成一条链，那么就是最差情况 O(n)；平均是 O(logn)。
- 构建 BST 平均 O(n^2) O(nlogn)
