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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return -1;
        queue<TreeNode*> q;
        if(root) q.push(root);
        int res;
        while(!q.empty()) {
            int s = q.size();
            res = q.front()->val;
            for(int i=0; i<s; i++) {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return res;
    }
};