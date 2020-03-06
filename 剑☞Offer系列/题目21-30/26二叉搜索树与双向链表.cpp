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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        // 中序遍历
        if(pRootOfTree == nullptr)
            return nullptr;
        TreeNode* head = nullptr;
        InOrder(pRootOfTree, head);
        while(head->left != nullptr)
            head = head->left;
        return head;
    }
    
    void InOrder(TreeNode* node, TreeNode* &head) {
        if(node == nullptr)
            return;
        if(node->left != nullptr)
            InOrder(node->left, head);
        node->left = head;
        if(head != nullptr)
            head->right = node;
        head = node;
        if(node->right != nullptr)
            InOrder(node->right, head);
    }
};
