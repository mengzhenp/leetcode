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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int hr = 0, hl = 0;
        TreeNode *l = root, *r = root;
        while(l) {hl += 1; l = l->left;}
        while(r) {hr += 1; r = r->right;}
        if (hl == hr) return pow(2, hr) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};