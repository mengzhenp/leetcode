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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* now = root;
        if (!root) return;
        while(now) {
            if (!now->right && !now->left && st.empty()) break;
            if (now->right) {st.push(now->right); now->right = nullptr;}
            if (now->left) {
                now->right = now->left;
                now->left = nullptr;
                now = now->right;
            } else {
                now->right = st.top();
                st.pop();
                now = now->right;
            }
        }
    }
};