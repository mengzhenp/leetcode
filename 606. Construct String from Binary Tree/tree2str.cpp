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
    string tree2str(TreeNode* t) {
        stringstream ans;
        if (t == nullptr) return "";
        string leftstr = tree2str(t->left);
        string rightstr = tree2str(t->right);
        if (leftstr.length() == 0 && rightstr.length() == 0) {
            ans << t->val;
        } else {
            if (rightstr.length() == 0) {
                ans << t->val << '(' << leftstr << ')'; 
            } else {
                ans << t->val << '(' << leftstr << ")(" << rightstr << ')';
            }
        }
        return ans.str();
    }
};