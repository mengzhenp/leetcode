class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int ans = 0;
        int len = prices.size()-1;
        for(int i = 1; i <= len; i++) {
            int tmp = maxp(prices, 0, i) + maxp(prices, i, len);
            ans = max(ans, tmp);
        }
        return ans;
    }
private:
    int maxp(vector<int>& prices, int start, int end) {
        if(end - start < 1) return 0;
        int ans = 0;
        int buyp = prices[start];
        for(int i = start+1; i <= end; i++) {
            if(prices[i] < buyp) buyp = prices[i];
            if(prices[i] > buyp) ans = max(ans, prices[i]-buyp);
        }
        return ans;
    }
};