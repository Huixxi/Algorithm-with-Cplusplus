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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        if(root != NULL)
            s1.push(root);
        vector<int> temp;
        TreeNode* tp;
        while(!s1.empty() || !s2.empty()) {
            while(!s1.empty()) {
                tp = s1.top();
                s1.pop();
                if(tp->left)
                    s2.push(tp->left);
                if(tp->right)
                    s2.push(tp->right);
                temp.push_back(tp->val);
            }
            res.push_back(temp);
            temp.clear();
            while(!s2.empty()) {
                tp = s2.top();
                s2.pop();
                if(tp->right)
                    s1.push(tp->right);
                if(tp->left)
                    s1.push(tp->left);
                temp.push_back(tp->val);
            }
            if(!temp.empty())
                res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};
