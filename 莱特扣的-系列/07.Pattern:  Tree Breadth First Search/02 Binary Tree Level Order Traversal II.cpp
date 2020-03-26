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
    void levelTraversal(TreeNode* root, int level) {
        if(res.size() <= level) {
            vector<int> temp{root->val};
            res.push_back(temp);
        }
        else
            res[level].push_back(root->val);
            
        if(root->left)
            levelTraversal(root->left, level + 1);
        if(root->right)
            levelTraversal(root->right, level + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root != NULL)
            levelTraversal(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};
