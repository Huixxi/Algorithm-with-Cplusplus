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
    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(!pRoot)
            return res;
        stk1.push(pRoot);
        while(!stk1.empty() || !stk2.empty()) {
            vector<int> v;
            if(!stk1.empty())
                while(!stk1.empty()) {
                    if(stk1.top()->left)
                        stk2.push(stk1.top()->left);
                    if(stk1.top()->right)
                        stk2.push(stk1.top()->right);
                    v.push_back(stk1.top()->val);
                    stk1.pop();
                }
            else
                while(!stk2.empty()) {
                    if(stk2.top()->right)
                        stk1.push(stk2.top()->right);
                    if(stk2.top()->left)
                        stk1.push(stk2.top()->left);
                    v.push_back(stk2.top()->val);
                    stk2.pop();
                }
            res.push_back(v);
        }
        return res;
    }
};
