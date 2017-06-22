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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int res = 0;
        while (!nodes.empty()) {
            res = max(res, diameterNode(nodes.front()));
            if (nodes.front()->left) nodes.push(nodes.front()->left);
            if (nodes.front()->right) nodes.push(nodes.front()->right);
            nodes.pop();
        }
        return res;   
    }
private:
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    int diameterNode(TreeNode* root) {
        if (root == nullptr) return 0;
        return depth(root->left) + depth(root->right);
    }
};