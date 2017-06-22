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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(depth(root->left) - depth(root->right)) < 2) 
            return (isBalanced(root->left) && isBalanced(root->right));
        return false;
    }
private:
    int depth(TreeNode* root) {
        if (!root) return 0;
        int res = 1;
        res += max(depth(root->left), depth(root->right));
        return res;
    }
};