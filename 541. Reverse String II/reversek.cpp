class Solution {
public:
    string reverseStr(string s, int k) {
        if (k < 2) return s;
        if (s.length() < 2) return s;
        int i = 0;
        while (i < s.length() - k && s.length() >= k) {
            for (int j = i; j < i+k/2; j++) {
                swap(s[j],s[2*i + k - 1 - j]);
            }
            i += 2 * k;
        }
        std::cout<<i<<endl;
        if (i >= s.length()) return s;
        for (int l = i; l < (s.length() + i)/2; l++) {
            swap(s[l], s[i+s.length()-1-l]);
        }
        return s;
    }
};