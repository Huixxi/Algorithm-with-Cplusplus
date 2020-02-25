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
    char* Serialize(TreeNode *root) {    
        // 前序遍历
        PreOrder(root);
        int* str = new int[v.size()];
        for(int i = 0; i < v.size(); ++i)
            str[i] = v[i];
        return (char*)str;
    }
    TreeNode* Deserialize(char *str) {
        int* p = (int*)str;
        return helper(p);
    }
    void PreOrder(TreeNode* root) {
        if(!root) {
            v.push_back(0xFFFFFFFF);
            return;
        }
        v.push_back(root->val);
        PreOrder(root->left);
        PreOrder(root->right);
    }
    TreeNode* helper(int*& str) {
        if(*str == 0xFFFFFFFF) {
            ++str;
            return nullptr;
        }
        TreeNode* root = new TreeNode(*str);
        ++str;
        root->left = helper(str);
        root->right = helper(str);
        return root;
    }
private:
    vector<int> v;
};
