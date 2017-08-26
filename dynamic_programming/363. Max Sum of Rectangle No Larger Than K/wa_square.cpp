class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int upper) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int len = min(m, n);
        //vector<vector<vector<int>>> dp(m, vector<int>(n, vector<int>(len, 0)));
        int dp[m][n][len+1];
        for(int k = 0; k <= len; k++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    dp[i][j][k] = 0;
                }
            }
        }
        // dp[i][j]--left top point (i, j) and edge length is k
        int res = 0;
        for(int k = 1; k <= len; k++) {
            for(int i = m-1; i >= 0; i--) {
                for(int j = n-1; j >= 0; j--) {
                    if((i + k > m) || (j + k > n)) continue;
                    if(k%2 == 0) {
                        dp[i][j][k] = dp[i][j][k/2] + dp[i+k/2][j][k/2] + dp[i][j+k/2][k/2] + dp[i+k/2][j+k/2][k/2];
                    } else {
                        if(k == 1) dp[i][j][k] = matrix[i][j];
                        else {
                            dp[i][j][k] = matrix[i][j] + dp[i+1][j+1][k-1];
                            for(int l = 1; l < k; l++) {
                                dp[i][j][k] += (matrix[i][j+l] + matrix[i+l][j]);
                            }    
                        }
                    }
                    if(dp[i][j][k] == upper) return upper;
                    if(dp[i][j][k] < upper) res = max(res, dp[i][j][k]);
                }
            }
        }
        return res;
    }
};