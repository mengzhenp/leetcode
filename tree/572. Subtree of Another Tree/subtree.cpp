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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr) return false;
        if (isSameTree(s, t)) return true;
        if (isSubtree(s->left, t) || isSubtree(s->right, t)) return true;
        return false;
    }
private:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        if (s->val == t->val) return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        return false;
    }
};