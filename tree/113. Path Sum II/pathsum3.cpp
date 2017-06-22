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
        if (!root) return res;
        vector<int> v = {root->val};
        sum -= root->val;
        if(!root->left && !root->right && sum == 0) {res.push_back(v); return res;}
        path(res, v, root->left, sum);
        path(res, v, root->right, sum);
        return res;
    }
private:
    void path(vector<vector<int>>& res, vector<int>& v, TreeNode* root, int sum) {
        if (root == nullptr) return;
        vector<int> newv = copyVec(v);
        newv.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right && sum == 0) {res.push_back(newv); return;}
        path(res, newv, root->left, sum);
        path(res, newv, root->right, sum);
    }
    vector<int> copyVec(vector<int> v) {
        vector<int> res;
        for(int i = 0; i < v.size(); i++) {
            res.push_back(v[i]);
        }
        return res;
    }
};