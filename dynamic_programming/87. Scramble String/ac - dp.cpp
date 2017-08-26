class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        int len = s1.length();
        bool dp[len][len][len+1] = {false};
        //initialize ---- 
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        //-----
        for(int l = 2; l <= len; l++) {
            // l : length of the substr
            for(int i = 0; i <= len-l; i++) {
                // i : start of the substr of s1
                // i + l - 1 < len
                for(int j = 0; j <= len-l; j++) {
                    // j : start of the substr of s2
                    bool ans = false;
                    for(int k = 1; k < l; k++) {
                        ans = ans || (dp[i][j][k] && dp[i+k][j+k][l-k]) || (dp[i][j+l-k][k] && dp[i+k][j][l-k]);
                        if(ans) break;
                    }
                    dp[i][j][l] = ans;
                    
                }
            }
        }
            
        return dp[0][0][len];
    }
};