class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        bool hasZero = false;
        nums.push_back(n+1);
        for (int i = 0; i < n; i++) {
            if (nums[abs(nums[i])] == 0) hasZero = true;
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        } 
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i;
            if (nums[i] == 0 && !hasZero) return i;
        }
        return n;
    }
};