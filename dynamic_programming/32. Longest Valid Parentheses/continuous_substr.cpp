class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len <= 1) return 0;
        int dp[len] = {0};
        int ans = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == ')') {
                int laststart = i - dp[i-1] - 1;
                if (laststart >= 0 && s[laststart] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if (laststart > 0) {
                        dp[i] += dp[laststart-1];
                    }
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};