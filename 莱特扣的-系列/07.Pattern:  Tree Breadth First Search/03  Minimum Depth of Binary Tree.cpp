/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res = 0, m = 10000;
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right) {
            m = min(m, res + 1);
            return m;
        }
        ++res;
        if(root->left)
            minDepth(root->left);
        if(root->right)
            minDepth(root->right);
        --res;
        return m;
    }
};
