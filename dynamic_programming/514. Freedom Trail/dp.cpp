class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> m;  
        for(int i = 0; i < ring.length(); i++) {
            if(m.find(ring[i]) == m.end()) {
                m[ring[i]] = {i};
            } else {
                m[ring[i]].push_back(i);
            }
        }
        //-----------dp-------------
        int keysize = key.size();
        int ringsize = ring.size();
        vector<vector<int>> dp(ringsize, vector<int>(keysize+1, 0));
        //dp[j][i]----when ring is in pos j and key is in pos i
        //----------------
        for(int i = keysize-1; i > 0; i--) {
            for(int nnow:m[key[i-1]]) {
                int dist = INT_MAX, totaldist = INT_MAX;
                if(m.find(key[i]) == m.end()) return 1061109567;
                for(int nnext:m[key[i]]) {
                    dist = min(abs(nnow - nnext), ringsize - abs(nnow - nnext));
                    totaldist = min(totaldist, dist + dp[nnext][i+1]);
                }
                dp[nnow][i] = totaldist; 
            }
        }
        //----
        // for beginning, nnow = 0; keypos = 0;
        int d = INT_MAX, t = INT_MAX;
        for(int nnext:m[key[0]]) {
            d = min(nnext, ringsize-nnext);
            t = min(t, d + dp[nnext][1]);
        }
        //----
        return t + keysize;
    }
};
/*
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> m;  
        for(int i = 0; i < ring.length(); i++) {
            if(m.find(ring[i]) == m.end()) {
                m[ring[i]] = {i};
            } else {
                m[ring[i]].push_back(i);
            }
        }
        int pos = 0;
        int res = key.size();
        int rs = ring.size();
        for(int i = 0; i < key.length(); i++) {
            char c  = key[i];
            int mindial = INT_MAX;
            int newpos;
            if(m.find(c) == m.end()) return 1061109567;
            for(int ind : m[c]) {
                int dis = min(abs(pos - ind), rs - abs(pos - ind));
                if(dis < mindial) {
                    mindial = dis;
                    newpos = ind;
                }
            }
            res += mindial;
            pos = newpos;
        }
        return res;
    }
};
*/