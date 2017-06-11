class Solution {
public:
    void swapvector(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < v1.size(); i++) {
            swap(v1[i], v2[i]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; i++) {
            swapvector(matrix[i], matrix[n-i-1]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }    
        }//transpose
    }
};