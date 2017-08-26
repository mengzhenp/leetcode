class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<int>> dp(nums.size(), vector<int>(m+1, 0));
        // dp[i][j] = max(sum(nums[i~k]), dp[k+1][j-1]);
        long sum = 0;
        for(int i = nums.size()-1; i >= 0; i--) {
            sum += nums[i];
            dp[i][1] = (int)sum; 
        }
        //----------
        for(int j = 2; j <= m; j++) {
            for(int i = nums.size()-j; i >= 0; i--) {
                int tmpsum = 0;
                int nextstart = i;
                bool largertmpsum = false;
                while(nextstart < nums.size()-j+1) {
                    tmpsum += nums[nextstart];
                    nextstart += 1;
                    if(tmpsum > dp[nextstart][j-1]) {
                        largertmpsum = true;
                        break;
                    }
                    if(tmpsum > INT_MAX - nums[nextstart] || tmpsum == dp[nextstart][j-1]) break;
                }
                if(!largertmpsum) dp[i][j] = dp[nextstart][j-1];
                else dp[i][j] = min(dp[nextstart-1][j-1], tmpsum);
            }
        }
        return dp[0][m];
    }
};