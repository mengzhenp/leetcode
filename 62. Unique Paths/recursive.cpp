class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        if (m == 1 && n == 1) return 1;
        if (m + n <= 3) return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};