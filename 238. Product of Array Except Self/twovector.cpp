class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> fromBegin(n, 0);
        vector<int> toEnd(n, 0);
        fromBegin[0] = 1; // from 1~n-1, except nums[n-1]
        toEnd[n-1] = 1;//from 0~n-2, except nums[0]
        for (int i = 1; i < n; i++) {
            fromBegin[i] = fromBegin[i-1] * nums[i-1];
            toEnd[n-i-1] = toEnd[n-i] * nums[n-i];
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            res[i] = fromBegin[i] * toEnd[i];
        }
        return res;
    }
};