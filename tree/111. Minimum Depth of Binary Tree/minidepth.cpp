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
    int mini;
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (!root->left && !root->right) return 1;
        mini = INT_MAX;
        int d = depth(root, 0);
        return mini;
    }
private:
    int depth(TreeNode* root, int d) {
        if (!root->left && !root->right) return d + 1;
        if (root->left && root->right) d = min(depth(root->left, d+1),depth(root->right, d+1));
        else if (root->left) d = depth(root->left, d+1);
             else d = depth(root->right, d+1);
        mini = min(mini, d);
        return d; 
    }
};