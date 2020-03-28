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
    int res = 0, temp = 0;
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return res;
        temp = temp * 10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            res += temp;
            temp /= 10;
            return res;
        }
        sumNumbers(root->left);
        sumNumbers(root->right);
        temp /= 10;
        return res;
    }
};
