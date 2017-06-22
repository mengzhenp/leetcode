/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key) {
            if (!root->left && !root->right) return nullptr; 
            else if (!root->left) return root->right;
            else if (!root->right) return root->left;
            else {
                //findmin----------------
                TreeNode* now = root->right;
                while(now->left) now = now->left;
                TreeNode* newroot = new TreeNode(now->val);
                newroot->right = deleteNode(root->right, now->val);
                newroot->left = root->left;
                return newroot;
            }
        } 
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};