// go through the longer string --  O(m)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int matchlength = 0;
        int checkt = 0;
        for (int i = 0; i < s.length(); i++) {
            char temp = s.at(i);
            for (;checkt < t.length(); checkt++) {
                if (t.at(checkt) == temp) {
                    matchlength++;
                    checkt++;
                    break; 
                }
            }
            if (checkt >= t.length()) break;
        }
        return matchlength == s.length();
    }
};