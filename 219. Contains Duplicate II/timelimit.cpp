class Solution {
public:
    int min(int a, int b) {
        if (a > b) return b;
        return a;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        if (k <= 0) return false;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i+1; j < min(i + k + 1, nums.size()); j++) {
                if (nums[i] == nums[j]) return true;    
            }
        }
        return false;
    }
};