/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* levelOrderSuccessor(TreeNode* root, TreeNode* key) { 
    // Base Case 
    if(root == NULL) 
        return NULL; 
  
    // If root equals to key 
    if(root == key) { 
        // If left child exists it will be 
        // the Postorder Successor 
        if (root->left) 
            return root->left; 
  
        // Else if right child exists it will be 
        // the Postorder Successor 
        else if (root->right) 
            return root->right; 
        else
            return NULL; // No Successor 
    } 
  
    // Create an empty queue for level order traversal 
    queue<TreeNode*> q; 
  
    // Enqueue Root 
    q.push(root); 
  
    while(!q.empty()) { 
        TreeNode* nd = q.front(); 
        q.pop(); 
  
        if(nd->left != NULL) { 
            q.push(nd->left); 
        } 
  
        if(nd->right != NULL) { 
            q.push(nd->right); 
        } 
  
        if(nd == key) 
            break; 
    } 
    if(q.empty())
        return NULL;
    return q.front(); 
} 
