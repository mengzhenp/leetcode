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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res; 
        getPreorder(res, root);
        return res;
    }
private:
    void getPreorder(vector<int>& res, TreeNode* root) {
        if(!root) return;
        res.push_back(root->val);
        getPreorder(res, root->left);
        getPreorder(res, root->right);
    }
};