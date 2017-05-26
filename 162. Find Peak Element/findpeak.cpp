class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[1] < nums[0]) return 0;
        int low = 1;
        int high = nums.size()-2;
        if (nums.back() > nums[high]) return nums.size()-1;
        int mid;
        while (high > low) {
            mid = (low + high)/2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid + 1]) return mid;
            else {
                if (nums[mid] <= nums[mid - 1]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return low;
    }
};