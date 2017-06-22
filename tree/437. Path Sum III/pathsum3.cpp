/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return pathFromNode(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int pathFromNode(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return (root->val == sum) + pathFromNode(root->left, sum-root->val) + pathFromNode(root->right, sum-root->val);
    }
};

