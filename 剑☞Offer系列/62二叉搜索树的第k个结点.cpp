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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot)
            return nullptr;
        dfs(pRoot);
        if(res.size() < k || k <= 0)  // 注意k可能小于0
            return nullptr;
        return res[k-1];
    }
private:
    vector<TreeNode*> res;
    void dfs(TreeNode* node) {
        if(node) {
            dfs(node->left);
            res.push_back(node);
            dfs(node->right);
        }
    }
};
