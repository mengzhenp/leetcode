class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        string res = "";
        for (int i = 0; i < min(strs[0].size(), strs[1].size()); i++) {
            if (strs[0][i] == strs[1][i]) res += strs[0][i];
            else break;
        }
        for (int i = 2; i < strs.size(); i++) {
            int j = 0;
            if (strs[i].length() < res.length()) res = res.substr(0, strs[i].length());
            while (j < res.length()) {
                if (strs[i][j] != res[j]) {
                    res = res.substr(0, j);
                    break;
                }
                j++;
            }
            if (res.length() == 0) return "";
        }
        return res;
    }
};