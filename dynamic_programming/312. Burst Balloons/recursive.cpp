//recursive method
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        return maxcoins(nums);
    }
private:
    int maxcoins(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int data = nums[i];
            nums.erase(nums.begin()+i);
            int resi = maxcoins(nums);
            nums.insert(nums.begin()+i, data);
            if(i == 0) {
                ans = nums[0] * nums[1] + resi;
            } else if(i == nums.size()-1) {
                ans = max(ans, nums[i] * nums[i-1] + resi);
            } else {
                ans = max(ans, nums[i] * nums[i-1] * nums[i+1] + resi);
            }
        }
        return ans;
    }
};