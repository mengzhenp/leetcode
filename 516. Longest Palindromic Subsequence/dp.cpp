class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (s.empty()) return 0;
        vector<vector<int>> dp(n, vector<int>(n+1));
        for (int i = n-1; i >= 0; i--) {
            dp[i][i] = 1;
            if (s[i] == s[i+1]) dp[i][i+1] = 2;
            else dp[i][i+1] = 1;
            for (int j = i+2; j < n; j++) {
                if (s[i] == s[j]) dp[i][j] = max(max(dp[i+1][j], dp[i][j-1]), dp[i+1][j-1]+2);
                else dp[i][j] = max(max(dp[i+1][j], dp[i][j-1]), dp[i+1][j-1]);
            }
        }
        return dp[0][n-1];
    }
};