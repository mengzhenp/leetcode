class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if (len < 3) return 0;
        vector<pair<long, int>> tmp;
        vector<vector<pair<long, int>>> dp(len, tmp);
        int ans = 0;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)A[i]-(long)A[j];
                bool found = false;
                for (auto p:dp[j]) {
                    if (p.first == diff) {
                        dp[i].push_back(make_pair(diff, p.second+1));
                        if (p.second > 1) {
                            //cout << i << "~~~" << j << endl;
                            //cout << p.first << " " << diff << endl;
                            ans += (p.second-1);
                        }
                        found = true;
                    }
                }
                if (!found) dp[i].push_back(make_pair(diff, 2)); 
            }
        }
        return ans;
    }
};