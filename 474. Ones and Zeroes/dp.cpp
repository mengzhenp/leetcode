class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int numsZero;
        int numsOne;
        
        for (auto &s : strs) {
            numsZero = 0;
            numsOne = 0;
            for (auto c : s) {
                if (c == '0') numsZero++;
                if (c == '1') numsOne++;
            }
            for (int i = m; i >= numsZero; i--) {
                for (int j = n; j >= numsOne; j--) {
                    dp[i][j] = max(dp[i-numsZero][j-numsOne] + 1, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};