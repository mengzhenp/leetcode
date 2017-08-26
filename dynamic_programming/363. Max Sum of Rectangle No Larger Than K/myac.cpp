class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int upper) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][1] = matrix[0][0];
        for(int i = 2; i <= m; i++) {
            dp[i][1] = dp[i-1][1] + matrix[i-1][0];
        }
        for(int i = 2; i <= n; i++) {
            dp[1][i] = dp[1][i-1] + matrix[0][i-1];
        }
        for(int i = 2; i <= m; i++) {
            for(int j = 2; j <= n; j++) {
                dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        int ans = INT_MIN;
        for(int k1 = 1; k1 <= m; k1++) {
            for(int k2 = 1; k2 <= n; k2++) {
                for(int i = 1; i <= m; i++) {
                    if(i < k1) continue;
                    for(int j = 1; j <= n; j++) {
                        if(j < k2) continue;
                        int thesum = dp[i][j] + dp[i-k1][j-k2] - dp[i][j-k2] - dp[i-k1][j];
                        if(thesum == upper) return upper;
                        if(thesum > upper) continue;
                        ans = max(ans, thesum);
                    }
                }
            }
        }
        return ans;
    }
};