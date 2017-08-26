class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if(len1 == 0) return len2;
        if(len2 == 0) return len1;
        long long dp[len1+1][len2+1];
        //dp[i][j] = mindistance from words[0~i] to word2[0~j]
        //boundary case:
        //dp[0][j] = j & dp[i][0] = i
        for(int i = 0; i <= len1; i++) {
            for(int j = 0; j <= len2; j++) {
                if(i == 0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                else if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};