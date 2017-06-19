class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int res = 1;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] == nums[i-1]) {
                res += 1;
                i++;
                if (i == nums.size()) break;
                while(nums.size() > i && nums[i] == nums[i-1]) {
                    nums.erase(nums.begin() + i);
                }
            } 
            if (i < nums.size()) res+=1;
            i++;
        }
        return res;
    }
};