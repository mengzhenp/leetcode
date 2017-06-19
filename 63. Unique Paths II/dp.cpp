class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int c = 0; c < col; c++) {
            if (obstacleGrid[0][c] == 0) dp[0][c] = 1;
            else {
                while(c < col) {dp[0][c] = 0; c++;}
                break;
            }
        }
        for (int r = 0; r < row; r++) {
            if (obstacleGrid[r][0] == 0) dp[r][0] = 1;
            else {
                while(r < row) {dp[r][0] = 0; r++;}
                break;
            }
        }
        for (int i = 1; i < row; i++) {
            for (int  j = 1; j < col; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
};