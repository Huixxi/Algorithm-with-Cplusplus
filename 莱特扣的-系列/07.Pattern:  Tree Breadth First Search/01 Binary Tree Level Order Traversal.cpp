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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        if(root != NULL)
            q1.push(root);
        vector<int> temp;
        TreeNode* frt;
        while(!q1.empty() || !q2.empty()) {
            while(!q1.empty()) {
                frt = q1.front();
                q1.pop();
                if(frt->left)
                    q2.push(frt->left);
                if(frt->right)
                    q2.push(frt->right);
                temp.push_back(frt->val);
            }
            res.push_back(temp);
            temp.clear();
            while(!q2.empty()) {
                frt = q2.front();
                q2.pop();
                if(frt->left)
                    q1.push(frt->left);
                if(frt->right)
                    q1.push(frt->right);
                temp.push_back(frt->val);
            }
            if(!temp.empty())
                res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};
