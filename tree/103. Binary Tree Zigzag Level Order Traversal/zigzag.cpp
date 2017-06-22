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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        bool flag = false;
        while(!q.empty()) {
            int s = q.size();
            vector<int> level;
            for (int i = 0; i < s; i++) {
                if(!flag) level.push_back(q.front()->val);
                if(flag) level.insert(level.begin(), q.front()->val);
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(level);
            flag = true ^ flag;
        }
        return res;    
    }
};