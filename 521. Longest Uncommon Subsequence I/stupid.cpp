class Solution {
public:
    int findLUSlength(string a, string b) {
        return a.compare(b) == 0 ? -1 : max(a.length(), b.length());        
    }
};