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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res = getTrees(1, n);
        if (n == 0) return {};
        return res;
    }
private:
    vector<TreeNode*> getTrees(int start, int end) {
        if (end < start) return {nullptr};
        if (end == start) {TreeNode* root = new TreeNode(start); return {root};}
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> lefts = getTrees(start, i-1);
            vector<TreeNode*> rights = getTrees(i+1, end);
            for (auto left:lefts) {
                for (auto right:rights) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};