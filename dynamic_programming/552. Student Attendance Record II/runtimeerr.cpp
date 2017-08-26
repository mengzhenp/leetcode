class Solution {
public:
    long mod = pow(10, 9) + 7;
    int checkRecord(int n) {
        if(n == 0) return 0;
        if(n == 1) return 3;
        long dp[n+1][6];
        // dp[0] -- all possibility
        // dp[1] -- the num of ending with L
        // dp[2] -- the num of ending with double L
        dp[2][0] = 8;
        dp[2][1] = 2;
        dp[2][2] = 1;
        //----------------------------
        dp[2][3] = 2;
        // not ending with L, no A
        dp[2][4] = 1;
        // ending with L, no A
        dp[2][5] = 1;
        // ending with LL, no A
        for(int i = 3; i <= n; i++) {
            // could add P + could add L + could add A
            dp[i][1] = modres(dp[i-1][0] - dp[i-1][1] - dp[i-1][2], mod); 
            dp[i][2] = dp[i-1][1];
            dp[i][3] = (dp[i-1][3] + dp[i-1][4] + dp[i-1][5])%mod;
            dp[i][4] = dp[i-1][3];
            dp[i][5] = dp[i-1][4];
            dp[i][0] = modres(2*dp[i-1][0]-dp[i-1][2]+dp[i][3], mod);
        }
        return (int)dp[n][0];
    }
private:
    long modres(long n, long m) {
        while(n <= 0) n += m;
        return n%m;
    }
};