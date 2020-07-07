# Tree Queries
* what is the kth ancestor of a node?
* what is the sum of values in the subtree of a node?
* what is the sum of values on a path between two nodes?
* what is the lowest common ancestor of two nodes?

## Finding Ancestors(`O(nlogn)`)
* [1483. Kth Ancestor of a Tree Node](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/)   

## Subtrees and Paths
A **tree traversal array(a kind of preorder traversal)** contains the nodes of a rooted tree in the order in which a depth-first search from the root node visits them. We also need a corresponding array that contains the **subtree size** of each node.     
* [508. Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/)

## Lowest Common Ancestor(For N-ary Tree)
The lowest common ancestor of two nodes of a rooted tree is the lowest node whose subtree contains both the nodes.   
**Method 1**   
We use two pointers that initially point to the two nodes whose lowest common ancestor we should find. First, we move one of the pointers upwards so that both pointers point to nodes at the same level.  

**Method 2**   
Another way to solve the problem is based on a tree traversal array: we add each node to the array always when the depth-first search walks through the node,
and not only at the first visit. Hence, a node that has `k` children appears `k + 1` times in the array and there are a total of `2n − 1` nodes in the array.

* [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

**Distances of Nodes**   
This problem can be reduced to finding their lowest common ancestor:   
First, we root the tree arbitrarily. After this, the distance of nodes `a` and `b` can be calculated using the formula *depth(a) + depth(b) − 2·depth(c)*, where `c` is the lowest common ancestor of `a` and `b` and `depth(s)` denotes the depth of node `s`. Take a binary tree for example:  
```c++
class Solution {
public:
    map<int, int> depthMap;  // assume the val of each node is unique
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, int depth) {
        if(root == p || root == q || root == nullptr)
            return root;
        depthMap[root->val] = depth;
        TreeNode* l = lowestCommonAncestor(root->left, p, q, depth + 1);
        TreeNode* r = lowestCommonAncestor(root->right, p, q, depth + 1);
        return l == nullptr ? r : (r == nullptr ? l : root);
    }
    
    int distanceOfNodes(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* c = lowestCommonAncestor(root, p, q, 0);
        return depthMap(p->val) + depthMap(q->val) - 2 * depthMap(c->val);
    }
};
```

## Offline Algorithms
**Merging data structures**   
**Lowest common ancestors**: Solve it with Union-Find data structure. [Tarjan's off-line lowest common ancestors algorithm](https://en.wikipedia.org/wiki/Tarjan%27s_off-line_lowest_common_ancestors_algorithm#:~:text=In%20computer%20science%2C%20Tarjan's%20off,the%20union%2Dfind%20data%20structure.)   




