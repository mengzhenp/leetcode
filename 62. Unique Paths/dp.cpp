class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        std::vector<vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        if (m + n <= 3) return 1;
        for (int i = 1; i <= n; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= m; i++) {
            dp[i][1] = 1;
            for (int j = 2; j <= n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }        
        }
        return dp[m][n];
    }
};