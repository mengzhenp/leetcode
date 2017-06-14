class Solution {
public:
    void reverseWords(string &s) {
        int i = 0;
        int j = 0;
        while(s[0] == ' ') s.erase(0,1);
        if(s.length() == 0) return;
        while(i < s.length()) {
            if (j < s.length() && s[j] != ' ') {
                j++;
                continue;
            }
            int k = i;
            while(k < (i+j)/2) {
                swap(s[k], s[i+j-1-k]);
                k++;
            }
            j++;
            while(j < s.length() && s[j] == ' ') s.erase(j, 1);
            i = j;
        }
        if (s[s.length()-1] == ' ') s.erase(s.length()-1, 1);
        i = 0;
        while (i < s.length()/2) {
            swap(s[i], s[s.length()-1-i]);
            i++;
        }
    }
};