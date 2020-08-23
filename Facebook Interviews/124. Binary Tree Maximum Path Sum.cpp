/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mxSum;
    }
    
    int dfs(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int l = dfs(root->left); l = max(l, 0);
        int r = dfs(root->right); r = max(r, 0);
        mxSum = max(mxSum, root->val + l + r);
        return root->val + max(l, r);
    }
};
