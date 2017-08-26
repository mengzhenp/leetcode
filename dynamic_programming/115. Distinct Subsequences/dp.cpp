class Solution {
public:
    int numDistinct(string s, string t) {
        unordered_map<char, vector<int>> m;
        for(int i = 0; i < s.length(); i++) {
            if(m.find(s[i]) == m.end()) m[s[i]] = {i};
            else m[s[i]].push_back(i);
        }
        int len = t.length();
        vector<unordered_map<int, int>> dp;
        // for every char in t, all possible pos, and the num of possibility for each pos
        for(int i = 0; i < len; i++) {
            unordered_map<int, int> tmp;
            if(m.find(t[i]) == m.end()) return 0;
            if(i == 0) {
                for(int n:m[t[i]]) {
                    tmp[n] += 1;
                }
            } else {
                for(int n:m[t[i]]) {
                    for(auto p:dp[i-1]) {
                        if(n > p.first) { // this one is latter than the last one
                            tmp[n] += p.second;
                        }
                    }
                }
            }
            if(tmp.size() == 0) return 0;
            dp.push_back(tmp);
        }
        int res = 0;
        for(auto p:dp[len-1]) {
            res += p.second;
        }
        return res;
    }
};