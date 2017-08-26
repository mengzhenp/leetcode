class Solution {
public:
    int mod = pow(10, 9) + 7;
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) return 0;
        
        int dp[len+1] = {1};
        if (s[0] != '*' && (s[0] > '9' || s[0] < '1')) return 0;
        
        if (s[0] == '*') dp[1] = 9;
        else dp[1] = 1;
        
        for (int i = 2; i <= len; i++) {
            if (s[i-1] != '*' && (s[i-1] > '9' || s[i-1] < '0')) return 0;
            
            if (s[i-1] == '0') {
                if (s[i-2] == '*') {
                    dp[i] = dp[i-2] * 2;
                    continue;
                }
                if (s[i-2] == '1' || s[i-2] == '2') {
                    dp[i] = dp[i-2];
                    continue;
                }
                return 0;
            }
            
            // as a new char
            long tmp1 = 0;
            if (s[i-1] == '*') tmp1 += 9;
            else tmp1 += 1;
            tmp1 *= (long)dp[i-1];
            tmp1 %= mod;
            
            if (s[i-2] == '0' || (s[i-2] >= '3' && s[i-2] <= '9')) {
                dp[i] = tmp1;
                continue;
            }
            
            // combine with the last one
            long tmp2 = 0;
            if (s[i-1] == '*') {
                if (s[i-2] == '*') {
                    tmp2 += 15;
                } else if (s[i-2] == '1'){
                    tmp2 += 9;
                } else {
                    tmp2 += 6;
                }
            } else {
                // '9' >= s[i-1] >= '1'
                if (s[i-1] <= '6') {
                    if (s[i-2] == '*') {
                        tmp2 += 2;
                    } else {
                        tmp2 += 1;
                    }
                } else {
                    if (s[i-2] != '2') {
                        tmp2 += 1;
                    }
                }
            }
            tmp2 *= (long)dp[i-2];
            tmp2 %= mod;
            dp[i] = (tmp1 + tmp2)%mod;
        }
        
        /*-----
        for (int i = 0; i <= len; i++) {
            cout << dp[i] << " ";
        }
        */
        return dp[len];
    }
};