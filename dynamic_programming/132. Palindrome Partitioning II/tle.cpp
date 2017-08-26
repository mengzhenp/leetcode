class Solution {
public:
    int minCut(string s) {
        int l = s.length();
        int dp[l+1] = {0};
        dp[0] = -1;
        for (int i = 2; i <= l; i++) {
            int tmp = dp[i-1] + 1;
            for (int j = 1; j < i; j++) {
                if (tmp > dp[j-1]+1 && isPalindrome(s, j-1, i-1)) {
                    tmp = min(tmp, dp[j-1] + 1);
                }
            }
            dp[i] = tmp;
        }
        return dp[l];
    }
private:
    bool isPalindrome(string s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            start += 1;
            end -= 1;
        }
        return start >= end;
    }
}