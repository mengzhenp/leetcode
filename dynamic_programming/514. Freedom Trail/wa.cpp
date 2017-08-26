// should consider when there is duplicates!!!
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