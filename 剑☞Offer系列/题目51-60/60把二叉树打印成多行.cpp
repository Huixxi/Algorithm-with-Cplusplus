/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        vector<int> v;
        if(!pRoot)
            return res;
        queue<TreeNode*> q;
        TreeNode* fr;
        q.push(pRoot);
        int next_level = 0;
        int curr_level = 1;
        while(!q.empty()) {
            fr = q.front();
            v.push_back(fr->val);
            q.pop();
            if(fr->left) {
                q.push(fr->left);
                ++next_level;
            }
            if(fr->right) {
                q.push(fr->right);
                ++next_level;
            }
            --curr_level;
            if(curr_level == 0) {
                curr_level = next_level;
                next_level = 0;
                res.push_back(v);
                v.clear();
            }
        }
        return res;
    }
};
