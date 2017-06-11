class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> res;
        int m = nums.size();
        int n = nums[0].size();
        if (n * m != r * c) return nums;
        int row = 0;
        int col = 0;
        vector<int> restemp;
        while (row < m) {
            restemp.push_back(nums[row][col]);
            if (col == n-1) {
                col = 0;
                row++;
            } else {
                col++;
            }
            if (restemp.size() == c) {
                res.push_back(restemp);
                restemp.clear();
            }
        }
        if (restemp.size() > 0) {
            while (restemp.size() < c) {
                restemp.push_back(0);
            }
            res.push_back(restemp);
        }
        return res;
    }
};