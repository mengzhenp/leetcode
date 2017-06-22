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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> v;
        path(res, v, root, sum);
        return res;
    }
private:
    void path(vector<vector<int>>& res, vector<int>& v, TreeNode* root, int sum) {
        if (root == nullptr) return;
        v.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right && sum == 0) {res.push_back(v);}
        path(res, v, root->left, sum);
        path(res, v, root->right, sum);
        v.pop_back();
    }
};