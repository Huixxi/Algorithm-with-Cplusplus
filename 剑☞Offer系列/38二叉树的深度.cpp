/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int res = 0, m = 0;
    vector<int> vec;
    int TreeDepth(TreeNode* pRoot)
    {
        // dfs
        if(!pRoot) {
            m = max(m, res);
            return res;
        }
        ++res;
        TreeDepth(pRoot->left);
        TreeDepth(pRoot->right);
        --res;
        return m;
    }
};
