class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        if (target <= nums[low]) return 0;
        if (target == nums[high]) return high;
        if (target > nums[high]) return high+1;
        int mid;
        while (high - low > 1) {
            mid = (high+low)/2;
            if (target == nums[mid]) return mid;
            if (target > nums[mid]) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low + 1;
    }
};