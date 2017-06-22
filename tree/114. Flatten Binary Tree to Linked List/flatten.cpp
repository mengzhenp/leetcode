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
    void flatten(TreeNode* root) {
        TreeNode* tail = flat(root);
    }
private:
    TreeNode* flat(TreeNode* root) {
        if (!root) return nullptr;
        if (!root->right && !root->left) return root;
        if (!root->left) return flat(root->right);
        if (!root->right) {
            root->right = root->left;
            root->left = nullptr;
            return flat(root->right);
        }
        TreeNode* taill = flat(root->left);
        TreeNode* tailr = flat(root->right);
        taill->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        return tailr;
    }
};