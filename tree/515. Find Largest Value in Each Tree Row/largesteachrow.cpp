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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(!root) return {};
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            int maxi = q.front()->val;
            for(int i = 0; i < s; i++) {
                maxi = max(maxi, q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(maxi);
        }
        return res;
    }
};