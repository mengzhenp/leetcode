/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode *root) {
        getRight(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* nextN = st.top();
        st.pop();
        getRight(nextN->right);
        return nextN->val;
    }
private:
    void getRight(TreeNode* root) {
        if (!root) return;
        TreeNode* p = root;
        while (p) {
            st.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */