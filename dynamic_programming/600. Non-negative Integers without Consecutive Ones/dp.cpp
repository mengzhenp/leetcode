class Solution {
public:
    int findIntegers(int num) {
        int dp[32];
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < 32; i++) dp[i] = dp[i-1] + dp[i-2];
        //
        int i = 30, sum = 0, pre_bit = 0;
        while(i >= 0) {
            if((num & (1 << i)) != 0) {
                sum += dp[i];
                if(pre_bit == 1) {
                    sum -= 1;
                    break;
                }
                pre_bit = 1;
            } else {
                pre_bit = 0;
            }
            i -= 1;
        }
        return sum + 1;
    }
};