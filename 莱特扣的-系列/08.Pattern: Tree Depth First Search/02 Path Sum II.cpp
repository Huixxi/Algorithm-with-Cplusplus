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
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        helper(root, sum);
        return res;
    }
    void helper(TreeNode* root, int sum) {
        if(root == NULL) 
            return;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && sum == root->val) {
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        helper(root->left, sum - root->val);
        helper(root->right, sum - root->val);
        temp.pop_back();
    }
};
