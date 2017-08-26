class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long sum = 0;
        for(int i:nums) sum += i;
        return split(nums, 0, m, sum);
    }
private:
    int split(vector<int>& nums, int start, int m, long sum) {
        if(start >= nums.size()) return 0;
        if(m == 1) return sum;
        int minres = sum%m == 0 ? sum/m : sum/m + 1;
        int tmpsum = 0;
        for(int i = start ; i < nums.size(); i++) {
            if(tmpsum > INT_MAX - nums[i]) {
                return max(tmpsum, split(nums, i, m-1, sum-tmpsum));
            }
            tmpsum += nums[i];
            if(tmpsum >= minres) {
                return min(max(tmpsum-nums[i], split(nums, i, m-1, sum-tmpsum+nums[i])), 
                          max(tmpsum, split(nums, i+1, m-1, sum-tmpsum)));
            }
        }
    }
};