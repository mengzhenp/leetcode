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
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) return {};
        map<int, int> table;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            if(table.find(q.front()->val) != table.end()) table[q.front()->val]++;
            else table[q.front()->val] = 1;
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        int maxi = 0;
        vector<int> res;
        for (auto ele:table) {
            if (ele.second > maxi) {res.clear(); res.push_back(ele.first); maxi = ele.second;}
            else if (ele.second == maxi) {res.push_back(ele.first);}
        }
        return res;
    }
};