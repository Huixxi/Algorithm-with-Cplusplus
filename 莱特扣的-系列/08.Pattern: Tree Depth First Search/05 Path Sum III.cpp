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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        unordered_map<int, int> mm;
        helper(root, sum, mm, 0, res);
        return res;
    }
    void helper(TreeNode* root, int sum, unordered_map<int, int>& mm, int s, int& res) {
        if(root) {
            if(s + root->val == sum)
                ++res;
            res += mm[s + root->val - sum];
            ++mm[s + root->val];
            helper(root->left, sum, mm, s + root->val, res);
            helper(root->right, sum, mm, s + root->val, res);
            --mm[s + root->val];
        }
    }
};
