class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() < 2) return 0;
        if(k == 0) return 0;
        k = min(k, (int)prices.size()/2);
        int state[2][2*k] = {0}; //2*i-1 -- sell the ith 2*i-2 -- buy the ith 
        int cur = 0, next = 1;
        //initialize------
        for(int j = 0; j < k; j++) {
            state[cur][2*j] = INT_MIN;
            state[cur][2*j+1] = 0;
        }
        //----------------
        for(int i = 0; i< prices.size(); i++) {
            state[next][0] = max(state[cur][0], -prices[i]);
            state[next][1] = max(state[cur][1], state[cur][0]+prices[i]);
            for(int j = 1; j < k; j++) {
                //buy
                state[next][2*j] = max(state[cur][2*j], state[cur][2*j-1]-prices[i]);
                //sell
                state[next][2*j+1] = max(state[cur][2*j+1], state[cur][2*j] + prices[i]);
            }
            swap(next, cur);
        }
        
        int ans = 0;
        for(int i = 0; i < k; i++) {
            ans = max(ans, state[cur][2*i+1]);
        }
        return ans;
    }
};