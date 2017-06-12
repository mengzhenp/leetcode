class Solution {
public:
    void reverse(vector<int>& nums, int begin, int end) {
        int i = begin, j = end;
        for (; i <= begin + (end-begin)/2; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        if (k <= 0) return;
        int n = nums.size();
        k = k%n;
        if (k == 0 || n == 0) return;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};