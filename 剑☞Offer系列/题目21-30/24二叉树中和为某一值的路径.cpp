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
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        if(root)
            dfsFind(root, expectNumber);
        return res;
    }
    
    void dfsFind(TreeNode* node,int eNum) {
        v.push_back(node->val);
        if(!node->left && !node->right) {
            if(eNum - node->val == 0)
                res.push_back(v);
        }
        else {
            if(node->left)
                dfsFind(node->left, eNum - node->val);
            if(node->right)
                dfsFind(node->right, eNum - node->val);
        }
        if(!v.empty())
            v.pop_back();
    }
private:
    vector<vector<int>> res;
    vector<int> v;
};
