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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int level = 1;
        int res = 1;
        TreeNode* now = root;
        while(now) {
            if (now->right) {res += pow(2, level); level += 1;}
            else break;
            now = now->right;
        }
        int residual = 1;
        int total = pow(2, level) - 2;
        now = root;
        while(total >= 0) {
            int path = total;
            int val = pow(2, level-1);
            for (int i = 1; i <= level; i++) {
                if (path & val) {now = now->right;}
                else {now = now->left;}
                val >>= 1;
            }
            if (now == nullptr) residual += 1;
            else break;
            total -= 1;
            now = root;
        }
        return res + pow(2, level) - residual;
    }
};