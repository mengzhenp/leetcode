class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        if(len < 2) return 0;
        if(stones[0] != 0 || stones[1] != 1) return 0;
        vector<pair<int, vector<int>>> dp(len, pair<int, vector<int>>(0, vector<int>()));
        // dp[i].first : the longest distence from this stone 
        // dp[i].second : possible distences from the last stone
        vector<int> tmp = {1};
        dp[1] = make_pair(3, tmp);
        for(int i = 2; i < len; i++) {
            int lastone = i-1;
            int lastdist = 0;
            while(dp[lastone].first >= stones[i] || dp[lastone].first == -1) {
                if(dp[lastone].first == -1) {
                    lastone--;
                    continue;
                }
                int dist = stones[i] - stones[lastone];
                for(int n : dp[lastone].second) {
                    if(abs(n-dist) <= 1) {
                        dp[i].second.push_back(dist);
                        lastdist = max(lastdist, dist);
                        break;
                    }
                }
                lastone--;
            }
            if(lastdist == 0) {
                dp[i].first = -1;
                continue;
            }
            dp[i].first = stones[i] + lastdist + 1;
            //cout << i << " " << dp[i].first<<endl;
        }
        return dp[len-1].first != -1;
    }
};