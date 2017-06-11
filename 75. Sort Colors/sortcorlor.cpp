class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int redpos = 0;
        int bluepos = n-1;
        for (int i = 0; i <= bluepos; i++) {
            if (nums[i] == 0) {
                swap(nums[redpos], nums[i]);
                redpos++;
            } else if (nums[i] == 2) {
                swap(nums[bluepos], nums[i]);
                bluepos--;
                i--;
            }
        } 
    }
};