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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        deque<TreeNode*> q; 
        vector<int> res;
        q.push_back(root);
        while(!q.empty()) {
            int s = q.size();
            res.push_back(q.back()->val);
            for (int i = 0; i < s; i++) {
                if(q.front()->left) q.push_back(q.front()->left);
                if(q.front()->right) q.push_back(q.front()->right);
                q.pop_front();
            }
        }
        return res;
    }
};