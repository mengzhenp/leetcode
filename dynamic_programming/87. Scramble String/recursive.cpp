// method-1 : recursive - timelimite
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        int len = s1.length();
        if(s1==s2) return true;
        bool ans = false;
        for(int i = 1; i < len; i++) {
            ans = ans || 
                (isScramble(s1.substr(0, i), s2.substr(0, i)) 
                 && isScramble(s1.substr(i, len-i), s2.substr(i, len-i))) ||
                (isScramble(s1.substr(0, i), s2.substr(len-i, i)) 
                 && isScramble(s1.substr(i, len-i), s2.substr(0, len-i)));
            if(ans) return true;
        }
        return ans;
    }
};