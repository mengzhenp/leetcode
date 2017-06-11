class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        if (n < 2) return 0;
        vector<int> dp;
        for (int i = 0; i < n; i++) {
            if (dp.size() == 0) dp.push_back(prices[i]);
            else if (dp.size() == 1) {
                if (dp[0] < prices[i]) dp.push_back(prices[i]);
                else dp[0] = prices[i];
            } else {
                if (dp[1] <= prices[i]) dp[1] = prices[i];
                else {
                    res += dp[1] - dp[0];
                    dp.clear();
                    dp.push_back(prices[i]);
                }
            }
            
        } 
        if (dp.size() == 2) res += dp[1]-dp[0];
        return res;
    }
};