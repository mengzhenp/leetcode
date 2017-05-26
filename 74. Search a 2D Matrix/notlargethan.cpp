class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int low = 0;
        int high = matrix.size()-1;
        int mid;
        while (high > low) {
            mid = (low + high + 1)/2;  
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] > target) high = mid-1;
            else low = mid;
        }
        int row = low;
        if (matrix[row][0] == target) return true;
        low = 0;
        high = matrix[row].size()-1;
        while (high > low) {
            mid = (low + high + 1)/2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] > target) high = mid-1;
            else low = mid;
        }
        if (matrix[row][low] == target) return true;
        return false;
    }
};