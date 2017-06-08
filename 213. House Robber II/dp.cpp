class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));
    }
private:
    int robber(vector<int>& nums, int s, int e) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[s] = nums[s];
        dp[s+1] = max(nums[s], nums[s+1]);
        for (int i = s + 2; i <= e; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[e];
    }
};