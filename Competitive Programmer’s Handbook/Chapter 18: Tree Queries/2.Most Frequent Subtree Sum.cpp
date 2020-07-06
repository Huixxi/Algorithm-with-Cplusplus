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
    unordered_map<int, int> cnt;
    int mx = 0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        preOrder(root);
        vector<int> res;
        for(auto k : cnt)
            if(k.second == mx)
                res.push_back(k.first);
        return res;
    }
    
    int preOrder(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = preOrder(root->left);
        int r = preOrder(root->right);
        int f = l + r + root->val;
        ++cnt[f];
        mx = max(mx, cnt[f]);
        return f;
    }
};
