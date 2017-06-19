class Solution {
public:
    void copyVec(vector<int>& a, vector<int>& b) {
        for (auto n:b) {
            a.push_back(n);
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> v(n, vector<int>());
        copyVec(v[n-1], triangle[n-1]);
        for (int i = n-2; i>=0; i--) {
            int s = triangle[i].size();
            for (int j = 0; j < s; j++) {
                v[i].push_back(min(triangle[i][j] + v[i+1][j], triangle[i][j] + v[i+1][j+1]));
            }
        }
        return v[0][0];
    }
};