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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        // 用queue实现广度优先搜索
        vector<int> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* r = q.front();
            res.push_back(r->val);
            q.pop();
            if(r->left != nullptr)
                q.push(r->left);
            if(r->right != nullptr)
                q.push(r->right);
        }
        return res;
    }
};
