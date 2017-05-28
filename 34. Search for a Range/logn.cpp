class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (nums.size() == 0) return {-1, -1};
        int low = 0;
        int high = n-1;
        int mid;
        int start;
        int end;
        while (low < high) {
            mid = (low + high)/2;
            if (nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        start = low;
        if (nums[start] != target) return {-1, -1};
        high = n-1;
        while (low < high) {
            mid = (low + high)/2 + 1; 
            if (nums[mid] > target) high = mid - 1;
            else low = mid;
        }
        end = low;
        std::vector<int> res;
        res = {start, end};
        return res;
    }
};