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
    bool isValidBST(TreeNode* root) {
        bool l=true, r=true;
        if(!root) return true;
        if(root->left && getLaggest(root->left) >= root->val) l = false;
        if(root->right && getSmallest(root->right) <= root->val) r = false;
        if (!l || !r) return false;
        return (isValidBST(root->right) && isValidBST(root->left));
    }
private: 
    int getLaggest(TreeNode* root) {
        while(root->right) root = root->right;
        return root->val;
    }
    int getSmallest(TreeNode* root) {
        while(root->left) root = root->left;
        return root->val;
    }
};