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
    bool existPath(TreeNode* root, int seq[], int n, int idx) {
        if(root == NULL)
            return (n == 0);
        if(root->left == NULL && root->right == NULL && root->val == seq[idx] && idx == n - 1) 
            return true;
        return (idx < n && root->val == seq[idx] && 
                (existPath(root->left, seq, n, idx + 1) || existPath(root->right, seq, n, idx + 1)));
    }
};
