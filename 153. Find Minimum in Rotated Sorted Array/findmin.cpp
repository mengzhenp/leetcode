class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1 || nums[0] < nums.back()) return nums[0];
        int low = 1;
        int high = nums.size()-1;
        int mid;
        while (high > low) {
            mid = (low + high)/2;
            if (nums[mid] > nums[low-1]) low = mid + 1;
            else high = mid;
        }
        return nums[low];
    }
};