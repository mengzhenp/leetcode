/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return codepre(root) + codein(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        int l = data.length();
        string preorder = data.substr(0, l/2);
        string inorder = data.substr(l/2, l/2);
        vector<int> pre = parseString(preorder);
        vector<int> in = parseString(inorder);
        int n = pre.size();
        return decode(pre, 0, n-1, in, 0, n-1);
    }
private:
    string itos(int a) {
        bool neg = false;
        string str = "";
        if(a<0) {
            neg = true; 
            if(a == -2147483648) return "-2147483648";
            a = -a;
        }
        if(a == 0) return "0";
        while(a > 0) {
            char c = a%10 + '0';
            str = c + str;
            a = a/10;
        }
        if(neg) str = "-"+str;
        return str;
    }
    int stoi(string str) {
        bool neg = false;
        int i = 0;
        if(str[0] == '-') {
            if(str == "-2147483648") return -2147483648;
            neg = true;
            i += 1;
        }
        int res = 0;
        while(i < str.length()) {
            char c = str[i];
            int a = c-'0';
            res = res*10 + a;
            i++;
        }
        return res;
    }
    string codepre(TreeNode* root) {
        string preorder = "";
        if(!root) return "";
        preorder = itos(root->val) + " " + codepre(root->left) + codepre(root->right);
        return preorder;    
    }
    string codein(TreeNode* root) {
        string inorder = "";
        if(!root) return "";
        inorder = codein(root->left) + itos(root->val) + " " + codein(root->right);
        return inorder;   
    }
    vector<int> parseString(string str) {
        vector<int> res;
        if(str == "") return res;
        int i = 0;
        while(i < str.length()) {
            string temp = "";
            while(str[i] != ' ') {
                temp += str[i];
                i++;
            }
            i++;
            res.push_back(stoi(temp));
        }
        return res;
    }
    TreeNode* decode(vector<int>& pre, int sp, int ep, vector<int>& in, int si, int ei) {
        if(sp > ep) return nullptr;
        TreeNode* root = new TreeNode(pre[sp]);
        if(sp == ep) return root;
        int separate = 0;
        while(in[separate] != root->val) separate++;
        root->left = decode(pre, sp+1, separate-si+sp, in, si, separate-1);
        root->right = decode(pre, separate-si+sp+1, ep, in, separate+1, ei);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));