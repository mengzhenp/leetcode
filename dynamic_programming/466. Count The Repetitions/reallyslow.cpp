class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(n1 == 0 || n2 == 0) return 0;
        int round1 = 1, round2 = 1, pos1 = 0, pos2 = 0, ans = 0;
        int l1 = s1.length();
        int l2 = s2.length();
        
        if (s1[0] == s2[0]) {
            if (!next(s2, n2, pos2, round2)) {
                int count = 0;
                for (int i = 0; i < s1.length(); i++) {
                    if (s1[i] == s2[0]) count += 1;
                }
                return count * n1;
            }
        }
        
        while (next(s1, n1, pos1, round1)) {
            if (pos1 == 0 && pos2 == 0 && round2 == 1) {
                return ans * (n1/(round1-1)) + getMaxRepetitions(s1, n1%(round1-1), s2, n2);
            }
            if (s1[pos1] == s2[pos2]) {
                if (!next(s2, n2, pos2, round2)) {
                    ans += 1;
                    pos2 = 0;
                    round2 = 1;
                }
            }
        }
        return ans;
    } 
private:
    bool next(string& s, int n, int& pos, int& round) {
        if (round == n && pos == s.length()-1) return false;
        if (pos == s.length()-1) {
            pos = 0;
            round += 1;
        } else {
            pos += 1;
        }
        return true;
    }
};