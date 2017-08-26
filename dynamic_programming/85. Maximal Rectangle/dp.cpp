class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        pair<int, int> tmp = make_pair(0, 0);
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, tmp));
        //first - row - up
        //second - col - left
        int ans = 0;
        //---------initialize---------
        if(matrix[0][0] == '1') {
            dp[0][0].first = 1;
            dp[0][0].second = 1;
            ans = max(ans, 1);
        } 
        for(int i = 1; i < m; i++) {
            if(matrix[i][0] == '1') {
                dp[i][0].first = dp[i-1][0].first + 1;
                dp[i][0].second = 1;
                ans = max(ans, dp[i][0].first);
            } 
        }
        for(int j = 1; j < n; j++) {
            if(matrix[0][j] == '1') {
                dp[0][j].first = 1;
                dp[0][j].second = dp[0][j-1].second + 1;
                ans = max(ans, dp[0][j].second);
            } 
        }
        //-----------------------------
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == '1') {
                    int height = dp[i-1][j].first + 1;
                    int width = dp[i][j-1].second + 1;
                    dp[i][j].first = height;
                    dp[i][j].second = width;
                    //find to up
                    ans = max(ans, width);
                    for(int ii = i-1; ii > i-height; ii--) {
                        if(dp[ii][j].second < width) {
                            width = dp[ii][j].second;
                        }
                        ans = max(ans, (i-ii + 1) * width);
                    }
                } 
            }
        }
        return ans;
    }
};
