class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if (l3 != l1 + l2) return false;
        if (l1 == 0) return s2.compare(s3) == 0;
        if (l2 == 0) return s1.compare(s3) == 0;
        
        bool dp[l1+1][l2+1] = {false};
        int k = 1;
        while (l1-k >= 0 && s1[l1-k] == s3[l3-k]) {
            dp[l1-k][l2] = true;
            k++;
        }
        k = 1;
        while (l2-k >= 0 && s2[l2-k] == s3[l3-k]) {
            dp[l1][l2-k] = true;
            k++;
        }
        dp[l1][l2] = true;
        //dp[i][j] == true: s1.substr(i) && s2.substr(j) is interleave of s3.substr(i+j)
        for (int i = l1-1; i >= 0; i--) {
            for (int j = l2-1; j >= 0; j--) {
                int pos = i + j;
                if (s3[pos] == s1[i] && s3[pos] == s2[j]) {
                    dp[i][j] = (dp[i+1][j] || dp[i][j+1]);
                } else if (s3[pos] == s1[i]) {
                    dp[i][j] = dp[i+1][j];
                } else if (s3[pos] == s2[j]) {
                    dp[i][j] = dp[i][j+1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        /*
        for (int i = 0; i <= l1; i++) {
            for (int j = 0; j <= l2; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */
        return dp[0][0];
    }
}