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
    int kthSmallest(TreeNode* root, int k) {
        return getIt(root, k);
    }
private:
    int getIt(TreeNode* root, int& k) {
        if (root) {
            int r = getIt(root->left, k);
            if (!k) return r;
            if (!--k) return root->val;
            if (k) return getIt(root->right, k);
        }
        return -1;
    }
};