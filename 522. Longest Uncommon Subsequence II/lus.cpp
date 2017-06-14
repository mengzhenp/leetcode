class Solution {
public:
    bool isNotSubstr(string str, vector<string>& strs) {
        if (strs.size() == 0) return true;
        for (int i = 0; i < strs.size(); i++) {
            int j = 0, k = 0;
            while (j < strs[i].length() && k < str.length()) {
                if (strs[i][j] == str[k]) {
                    j++;
                    k++;
                } else {
                    j++;
                }
            }
            if (k == str.length()) return false;
        }
        return true;
    }
    int findLUSlength(vector<string>& strs) {
        map<string, int> smap;
        vector<string> longstrs;
        for (int i = 0; i < strs.size(); i++) {
            if (smap.find(strs[i]) != smap.end()) {
                smap[strs[i]] += 1;
                longstrs.push_back(strs[i]);
            } else {
                smap.insert(pair<string, int>(strs[i], 1));
            }
        }
        int len = 0;
        for (auto record:smap) {
            if (record.second == 1 && record.first.size() > len && isNotSubstr(record.first, longstrs)) len = record.first.size();
        }
        return len == 0 ? -1 : len;
    }
};