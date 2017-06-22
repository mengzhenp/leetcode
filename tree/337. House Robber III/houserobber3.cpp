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
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (!root->right) {
            return max(root->val + rob(root->left->left) + rob(root->left->right), rob(root->left));
        } 
        if (!root->left) {
            return max(root->val + rob(root->right->left) + rob(root->right->right), rob(root->right));
        }
        return max(root->val + rob(root->right->left) + rob(root->right->right) + rob(root->left->left) + rob(root->left->right), rob(root->right) + rob(root->left));
    }
};