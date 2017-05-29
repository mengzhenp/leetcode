class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, res = nums.size();
        while (j < nums.size()) {
            sum += nums[j];
            if (sum >= s) {
                while (sum - nums[i] >= s) {
                    sum -= nums[i];
                    i++;
                }
                if (res > j - i + 1) res = j - i + 1;
            }
            j++;
        }
        if (i == 0 && sum < s) res = 0;
        return res;
    }
};