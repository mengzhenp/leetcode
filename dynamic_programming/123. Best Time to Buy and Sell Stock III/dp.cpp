class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int ans = 0;
        int len = prices.size()-1;
        vector<int> dp1(len+1, 0);
        vector<int> dp2(len+1, 0);
        maxp(prices, dp1, dp2);
        for(int i = 1; i <= len; i++) {
            //cout << i << " " << dp1[i] << " " << dp2[i] << endl;
            int tmp = dp1[i] + dp2[i];
            ans = max(ans, tmp);
        }
        return ans;
    }
private:
    void maxp(vector<int>& prices, vector<int>& dp1, vector<int>& dp2) {
        //dp1--from 0 to i
        int buyp = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] <= buyp) {
                buyp = prices[i];
                dp1[i] = dp1[i-1];
            }
            if(prices[i] > buyp) {
                dp1[i] = max(dp1[i-1], prices[i]-buyp);
            }
        }
        //dp2--from i to end
        int sellp = prices.back();
        for(int i = prices.size()-2; i >= 0; i--) {
            if(prices[i] >= sellp) {
                sellp = prices[i];
                dp2[i] = dp2[i+1];
            }
            if(prices[i] < sellp) {
                dp2[i] = max(dp2[i+1], sellp - prices[i]);
            }
        }
    }
};