class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m == 0) return 0;
        int n = dungeon[0].size();
        
        vector<pair<int, int>> tmp;
        vector<vector<vector<pair<int, int>>>> dp(m, vector<vector<pair<int, int>>>(n, tmp));
        //first -- now the value
        //second -- now the minimum
        //at most there are two candidiate for every grid
        
        //---initialize----
        dp[0][0].push_back(make_pair(dungeon[0][0], dungeon[0][0]));
        for (int i = 1; i < m; i++) {
            dp[i][0].push_back(
                make_pair(
                    dp[i-1][0][0].first + dungeon[i][0], 
                    min(dp[i-1][0][0].second, dp[i-1][0][0].first + dungeon[i][0])
                    )
                );
        }
                
        for (int i = 1; i < n; i++) {
            dp[0][i].push_back(
                make_pair(
                    dp[0][i-1][0].first + dungeon[0][i], 
                    min(dp[0][i-1][0].second, dp[0][i-1][0].first + dungeon[0][i])
                    )
                );
        }
        
        //---go through---
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int localval, minival;
                vector<pair<int, int>> tmp;
                //-------------------------------------------------------
                for (auto p:dp[i-1][j]) {
                    localval = p.first+dungeon[i][j];
                    minival = min(p.second, localval);
                    tmp.push_back(make_pair(localval, minival));
                }
                //-------------------------------------------------------
                for (auto p:dp[i][j-1]) {
                    localval = p.first+dungeon[i][j];
                    minival = min(p.second, localval);
                    tmp.push_back(make_pair(localval, minival));
                }
                
                removeInvalid(tmp);
                dp[i][j] = tmp;
                
            }
        }
        
        //--------result----
        int maxival = INT_MIN;
        for (auto p:dp[m-1][n-1]) {
            //cout << p.first << " " << p.second << endl;
            maxival = max(maxival, p.second);   
        }
        
        if (maxival > 0) return 1;
        else return 1-maxival;
    }
    
private:
    void removeInvalid(vector<pair<int, int>>& v) {
        if (v.size() <= 1) return;
        sort(v.begin(), v.end(), 
             [](pair<int, int>& p1, pair<int, int>& p2)
             {return p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second);});
        for (int i = 1; i < v.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (v[i].second <= v[j].second) {
                    v.erase(v.begin()+i);
                    i -= 1;
                    break;
                }
            }
        }
    }
};