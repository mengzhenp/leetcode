class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int size = 0;
            for (int k = i; nums[k] >= 0; size++) {
                int next = nums[k];
                if (next >= 0) {
                    nums[k] = -1;
                    k = next;
                }
            }
            res = max(res, size);
        }
        return res;
    }
};