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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        getSum(res, 0, root);
        return res;
    }
private:
    void getSum(int& res, int base, TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right) {res += base * 10 + root->val;return;}
        base = base*10 + root->val;
        getSum(res, base, root->left);
        getSum(res, base, root->right);
    }
};