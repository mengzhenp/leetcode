//O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int i = 0;
        int j = matrix[0].size()-1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
