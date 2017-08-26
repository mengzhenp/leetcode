class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> cut(n + 1);
        iota(cut.rbegin(), cut.rend(), -1);
        for (int i = n - 1; i >= 0; i--) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++)
                cut[l] = min(cut[l], cut[r + 1] + 1);
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++)
                cut[l] = min(cut[l], cut[r + 1] + 1);
        }
        return cut[0];
    }
};