class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l = s.length();
        if (l < 2) return false;
        for (int i = 1; i < l; i++) {
            if (s[i] == s[0] && l%i == 0) {
                int j = i;
                while (j < l) {
                    if (s.substr(0, i).compare(s.substr(j, i)) != 0) {
                        break;
                    }
                    j += i;
                }
                if (j == l) return true;
            }
        }
        return false;
    }
};