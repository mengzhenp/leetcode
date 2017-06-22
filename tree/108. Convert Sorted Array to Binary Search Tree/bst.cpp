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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size());
    }
private:
    TreeNode* bst(vector<int>& nums, int start, int end) {
        int n = end - start;
        if (n == 0) return nullptr;
        int pos = start + n/2;
        int val = nums[pos];
        TreeNode* root = new TreeNode(val);
        root->left = bst(nums, start, pos);
        root->right = bst(nums, pos+1, end);
        return root;
    }
};