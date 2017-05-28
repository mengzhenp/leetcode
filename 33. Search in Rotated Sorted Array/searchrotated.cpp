class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (target == nums[0]) return 0;
        int low = 0;
        int high = nums.size()-1;
        if (target == nums[high]) return high;
        int mid;
        while (high > low) {
            mid = (low + high)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[0]) {
                if (nums[mid] > target) {
                    if (target > nums[0]) high = mid;
                    else low = mid + 1;
                }
                else low = mid + 1;
            }
            else {
                if (nums[mid] > target) high = mid;
                else {
                    if (target > nums[0]) high = mid;
                    else low = mid + 1;
                }
            }
        }
        if (nums[low] == target) return low;
        return -1;
    }
};