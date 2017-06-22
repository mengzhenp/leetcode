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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode* parent = new TreeNode(0);
        parent->left = root;
        addRow(parent, v, d);
        return parent->left;
    }
private:
    void addRow(TreeNode* parent, int v, int d) {
        if(!parent) return;
        if(d==1) {
            
            if(parent->left) {
                TreeNode* newNode1 = new TreeNode(v);
                newNode1->left = parent->left;
                parent->left = newNode1;
            } else {
                TreeNode* newNode1 = new TreeNode(v);
                parent->left = newNode1;
            }
            
            if(parent->right) {
                TreeNode* newNode2 = new TreeNode(v);
                newNode2->right = parent->right;
                parent->right = newNode2;
            } else {
                TreeNode* newNode2 = new TreeNode(v);
                parent->right = newNode2;
            }
            return;
        } 
        addRow(parent->left, v, d-1);
        addRow(parent->right, v, d-1);
    }
};