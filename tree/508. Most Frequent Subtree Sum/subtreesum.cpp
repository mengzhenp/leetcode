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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        map<int, int> umap;
        int sum = subTreeSum(umap, root);
        int maxi = 0;
        for(auto kvp:umap) {
            maxi = max(kvp.second, maxi);
        }
        for(auto kvp:umap) {
            if(kvp.second == maxi) res.push_back(kvp.first);
        }
        return res;
    }
private:
    int subTreeSum(map<int, int>& umap, TreeNode* root) {
        if(!root) return 0;
        int sum = root->val + subTreeSum(umap, root->left) + subTreeSum(umap, root->right);
        if(umap.find(sum) != umap.end()) umap[sum]++;
        else umap[sum] = 1;
        return sum;
    }
};