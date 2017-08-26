class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        for(int i:nums) sum += i;
        return split(nums, 0, m, sum);
    }
private:
    int split(vector<int>& nums, int start, int m, int sum) {
        if(start >= nums.size()) return 0;
        if(m == 1) return sum;
        int minres = sum%m == 0 ? sum/m : sum/m + 1;
        int res = sum;
        int tmpsum = 0;
        for(int i = start ; i < nums.size(); i++) {
            tmpsum += nums[i];
            if(tmpsum >= minres) {
                return min(max(tmpsum-nums[i], split(nums, i, m-1, sum-tmpsum+nums[i])), 
                          max(tmpsum, split(nums, i+1, m-1, sum-tmpsum)));
            }
        }
    }
};