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
        vector<int> inorder;
        getInorder(inorder, root);
        return inorder[k-1];
    }
private:
    void getInorder(vector<int>& inorder, TreeNode* root) {
        if (!root) return;
        if (root->left) getInorder(inorder, root->left);
        inorder.push_back(root->val);
        getInorder(inorder, root->right);
    }
};