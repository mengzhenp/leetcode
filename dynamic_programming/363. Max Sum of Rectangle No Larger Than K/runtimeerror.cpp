class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int upper) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int len = min(m, n);
        //vector<vector<vector<int>>> dp(m, vector<int>(n, vector<int>(len, 0)));
        int dp[m][n][m+1][n+1];
        for(int k1 = 0; k1 <= m; k1++) {
            for(int k2 = 0; k2 <= n; k2++) {
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        dp[i][j][k1][k2] = 0;
                    }
                }
            }
        }
        // dp[i][j]--left top point (i, j) and edge length is k1, k2
        int res = 0;
        for(int k1 = 1; k1 <= m; k1++) {
            for(int k2 = 1; k2 <= n; k2++) {
                for(int i = m-1; i >= 0; i--) {
                    for(int j = n-1; j >= 0; j--) {
                        if((i + k1 > m) || (j + k2 > n)) continue;
                        if(i == m-1 && j == n-1) dp[i][j][k1][k2] = matrix[i][j];
                        else if(i == m-1) dp[i][j][k1][k2] = matrix[i][j] + dp[i][j+1][k1][k2-1];
                        else if(j == n-1) dp[i][j][k1][k2] = matrix[i][j] + dp[i+1][j][k1-1][k2];
                        else {
                            dp[i][j][k1][k2] = matrix[i][j] + dp[i+1][j+1][k1-1][k2-1];
                            for(int l1 = 1; l1 < k1; l1++) {
                                dp[i][j][k1][k2] += matrix[i+l1][j];
                            } 
                            for(int l2 = 1; l2 < k2; l2++) {
                                dp[i][j][k1][k2] += matrix[i][j+l2];
                            }
                        }
                        if(dp[i][j][k1][k2] == upper) return upper;
                        if(dp[i][j][k1][k2] < upper) res = max(res, dp[i][j][k1][k2]);
                    }
                }
            }
        }
        return res;
    }
};