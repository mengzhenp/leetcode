class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        if (n < 2) return 0;
        for (int i = 0; i < n-1; i++) {
            res += max(prices[i+1] - prices[i], 0);   
        } 
        return res;
    }
};