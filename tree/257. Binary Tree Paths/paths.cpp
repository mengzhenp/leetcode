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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        string str = "";
        int val = root->val;
        string c = itos(val);
        str += c;
        if (!root->left && !root->right) res.push_back(str); 
        else {
            if (root->left) paths(root->left, str, res);
            if (root->right) paths(root->right, str, res);
        }
        return res;
    }
private:
    void paths(TreeNode* root, string str, vector<string>& res) {
        str += "->";
        int val = root->val;
        string c = itos(val);
        str += c;
        if (!root->left && !root->right) {res.push_back(str); return;} 
        else {
            if (root->left) paths(root->left, str, res);
            if (root->right) paths(root->right, str, res);
        }
    }
    string itos(int a) {
        bool neg = false;
        if (a < 0) {neg = true; a = -a;}
        if (a == 0) return "0";
        string val = "";
        while (a > 0) {
            char temp = a%10 + '0';
            val = temp + val;
            a /= 10;
        } 
        return neg? '-' + val : val;
    }
};