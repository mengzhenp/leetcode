class Solution {
public:
    int count(vector<int>& nums, int S, int end) {
        if (end == 0) {
            if (nums[0] == 0 && S == 0) return 2;
            if (nums[0] == S || nums[0] == -S) return 1;
            else return 0;
        }
        if (nums[end] == 0) return 2 * count(nums, S, end-1);
        return count(nums, S-nums[end], end-1) + count(nums, S+nums[end], end-1);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0) return 0;
        return count(nums, S, nums.size()-1);
    }
};