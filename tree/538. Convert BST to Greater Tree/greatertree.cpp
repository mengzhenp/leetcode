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
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> reinorder;
        getReinorder(reinorder, root);
        if(!root) return nullptr;
        vector<int> dp(reinorder.size(), 0);
        dp[0] = reinorder[0]->val;
        for(int i = 1; i < reinorder.size(); i++) {
            dp[i] = reinorder[i]->val + dp[i-1];
            reinorder[i]->val = dp[i];
        }
        return root;
    }
private:
    void getReinorder(vector<TreeNode*>& reinorder, TreeNode* root) {
        if (!root) return;
        getReinorder(reinorder, root->right);
        reinorder.push_back(root);
        getReinorder(reinorder, root->left);
    }
};