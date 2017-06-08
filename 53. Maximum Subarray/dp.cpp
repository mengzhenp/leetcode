class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1] < 0 ? 0 : dp[i-1];
            dp[i] = dp[i] + nums[i];
            if (dp[i] > res) res = dp[i];
        }
        return res;
    }
};