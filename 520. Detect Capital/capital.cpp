class Solution {
public:
    bool isCapital(char c) {
        if (c - 'A' >= 0 && c - 'A' < 26) return true;
        return false;
    }
    bool detectCapitalUse(string word) {
        int l = word.length();
        if (l < 2) return true;
        if (isCapital(word[0])) {
           if (isCapital(word[1])) {
                for (int i = 2; i < word.length(); i++) {
                    if (!isCapital(word[i])) return false;
                } 
           } else {
                for (int i = 2; i < word.length(); i++) {
                    if (isCapital(word[i])) return false;
                }
           }
        } else {
            for (int i = 1; i < word.length(); i++) {
                if (isCapital(word[i])) return false;
            }     
        }
        return true;
    }
};