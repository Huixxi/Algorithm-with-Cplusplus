class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot)
            return true;
        int res = TreeDepth(pRoot);
        return res == -1 ? false : true;
    }
private:
    int TreeDepth(TreeNode* pRoot)
    {
        // dfs
        if(!pRoot)
            return 0;
        int left = TreeDepth(pRoot->left);
        if(left == -1)
            return -1;
        int right = TreeDepth(pRoot->right);
        if(right == -1)
            return -1;
        return abs(left - right) > 1 ? -1 : max(left, right) + 1;
    }
};
