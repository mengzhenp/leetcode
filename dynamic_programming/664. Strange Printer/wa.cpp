class Solution {
public:
    int strangePrinter(string s) {
        //dynamic programming
        int len = s.length();
        if (len == 0) return 0;
        bool showed[26] = {false};
        int dp[len] = {1};
        int starts[len] = {0};
        showed[s[0]-'a'] = true;
        for (int i = 1; i < len; i++) {
            if (!showed[s[i]-'a']) {
                dp[i] = dp[i-1] + 1;
                starts[i] = i;
                showed[s[i]-'a'] = true;
            } else {
                int pre = -1;
                int j = i-1;
                while (j >= 0) {
                    if (s[i] == s[j]) {
                        pre = j;
                        break;
                    } else {
                        j = starts[j];
                    }
                    j -= 1;
                }
                if (pre != -1) {
                    dp[i] = dp[i-1];
                    starts[i] = starts[pre];
                }
                else {
                    dp[i] = dp[i-1] + 1;
                    starts[i] = i;
                }
            }
        }
        /*
        for (int i = 0; i < len; i++) {
            cout << dp[i] << " ";
        }
        */
        return dp[len-1];
    }
};