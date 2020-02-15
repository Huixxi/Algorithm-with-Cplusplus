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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot)
            return true;
        return Compare(pRoot->left, pRoot->right);
    }
private:
    bool Compare(TreeNode* lnode, TreeNode* rnode) {
        if(lnode == nullptr)
            return rnode == nullptr;
        if(rnode == nullptr)
            return false;
        if(lnode->val == rnode->val)
            return Compare(lnode->left, rnode->right) && Compare(lnode->right, rnode->left);
        return false;
    }
};
