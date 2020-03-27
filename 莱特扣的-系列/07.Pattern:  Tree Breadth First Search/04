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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        double sum;
        int cnt;
        if(root)
            s1.push(root);
        while(!s1.empty() || !s2.empty()) {
            sum = 0.0;
            cnt = 0;
            while(!s1.empty()) {
                TreeNode* t = s1.top();
                s1.pop();
                sum += t->val;
                if(t->left)
                    s2.push(t->left);
                if(t->right)
                    s2.push(t->right);
                ++cnt;
            }
            if(cnt != 0)
                res.push_back(sum / cnt);
            sum = 0.0;
            cnt = 0;
            while(!s2.empty()) {
                TreeNode* t = s2.top();
                s2.pop();
                sum += t->val;
                if(t->left)
                    s1.push(t->left);
                if(t->right)
                    s1.push(t->right);
                ++cnt;
            }
            if(cnt != 0)
                res.push_back(sum / cnt);
        }
        return res;
    }
};
