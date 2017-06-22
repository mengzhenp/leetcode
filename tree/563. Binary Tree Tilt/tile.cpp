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
    int findTilt(TreeNode* root) {
        if (root == nullptr) return 0;
        return tileTree(root) + findTilt(root->left) + findTilt(root->right);
    }
private:
    int sumTree(TreeNode* root) {
        if (root == nullptr) return 0;
        return root->val + sumTree(root->left) + sumTree(root->right);
    }
    int tileTree(TreeNode* root) {
        if (root == nullptr) return 0;
        return abs(sumTree(root->left)-sumTree(root->right));
    }
};