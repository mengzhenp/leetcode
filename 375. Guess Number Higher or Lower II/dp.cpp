class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int j = 2; j <= n; j++) {
            for (int i = j-1; i > 0; i--) {
                int globalMin = INT_MAX;
                for (int k = i+1; k < j; k++) {
                    int localMax = k + max(dp[i][k-1], dp[k+1][j]);
                    globalMin = min(globalMin, localMax);
                }
                dp[i][j] = i+1 == j ? i : globalMin;
            }
        }
        return dp[1][n];
    }
};