class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), 
             [](pair<int, int>& p1, pair<int, int>& p2)
             {return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);});   
        int n = envelopes.size();
        vector<int> dp;
        dp.push_back(1);
        int ans = 1;
        for(int i = 1; i < n; i++){
            int res = 1;
            for(int j = i-1; j >= 0; j--) {
                if(res < dp[j] + 1 && envelopes[j].second < envelopes[i].second && envelopes[j].first < envelopes[i].first) {
                    res = dp[j] + 1;
                }
            }
            dp.push_back(res);
            ans = max(ans, res);
        }
        return ans;
    }
};