class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        vector<vector<int>> maxcs(nums.size(), vector<int>(nums.size(), 0));
        
        //from shorter to longer--- the first loop is length loop
        
        for(int len = 1; len <= n; len++) {
            for(int start = 1; start <= n - len + 1; start++) {
                int end = start + len - 1;
                int maxcoin = 0;
                for(int finalball = start; finalball <= end; finalball++) {
                    int coin = maxcs[start][finalball-1] + maxcs[finalball+1][end];
                    coin += nums[finalball] * nums[start-1] * nums[end+1];
                    maxcoin = max(coin, maxcoin);
                }
                maxcs[start][end] = maxcoin;
            }
        }
        return maxcs[1][n];
    }
};
//recursive method
/*
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
*/