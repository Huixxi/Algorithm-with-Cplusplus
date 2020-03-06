/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* root = new TreeNode(pre[0]);
        auto it = find(vin.begin(), vin.end(), pre[0]);
        int idx = distance(vin.begin(), it);
        vector<int> lpre(pre.begin()+1, pre.begin()+idx+1);
        vector<int> lvin(vin.begin(), it);
        vector<int> rpre(pre.begin()+idx+1, pre.end());
        vector<int> rvin(it+1, vin.end());
        if(vin.begin() != it)
            root->left = reConstructBinaryTree(lpre, lvin);
        if(it+1 != vin.end())
            root->right = reConstructBinaryTree(rpre, rvin);
        return root;
    }
};
