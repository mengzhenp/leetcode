class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.length() == 0) {
            return 1;
        }
        vector<vector<int>> f(2, vector<int>(t.length(), 0));
        for (int i = 0; i < s.length(); ++i) {
            int k = i % 2;
            for (int j = 0; j <= i && j < t.length(); ++j) {
                f[k][j] = f[1 - k][j];
                if (s[i] == t[j]) {
                    f[k][j] += (j == 0 ? 1 : f[1 - k][j - 1]);
                }
            }
        }
        return f[1 - s.length() % 2][t.length() - 1];
    }
};