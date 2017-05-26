class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int low = 1;
        int high = n;
        int mid;
        while (high > low) {
            mid = (low + high)/2;
            int count = 0;
            for (int num:nums) {
                if (num <= mid) {
                    count++;
                }
            }
            if (count <= mid) low = mid + 1;
            else high = mid;
        }
        return high;
    }
};

