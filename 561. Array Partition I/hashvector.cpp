class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> table(20001, 0);
        for (int i = 0; i < n; i++) {
            table[nums[i] + 10000]++;
        }
        bool flag = 1;
        int res = 0;
        for (int i = 0; i < 20001;) {
            if (table[i] > 0) {
                if (flag) {
                    res += i - 10000;
                    table[i]--;
                    flag = 0;
                } else {
                    table[i]--;
                    flag = 1;
                }
            } else {
                i++;
            }
        }
        return res;
    }
};