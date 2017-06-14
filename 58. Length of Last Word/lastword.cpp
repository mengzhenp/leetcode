class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        int res = 0;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0) {
            if (s[i] == ' ') break;
            else {
                res += 1;
                i--;
            }
        }
        return res;
    }
};