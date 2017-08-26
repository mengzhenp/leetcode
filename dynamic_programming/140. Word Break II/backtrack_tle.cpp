class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string tmp;
        backtrack(ans, tmp, wordDict, s, 0);
        return ans;
    }
private:
    void backtrack(vector<string>& ans, string tmp, vector<string>& wordDict, string s, int start) {
        if (start == s.length()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < wordDict.size(); i++) {
            int len = wordDict[i].length();
            if (start + len <= s.length() && wordDict[i] == s.substr(start, len)) {
                string newtmp = tmp;
                newtmp += tmp.size()? (" " + wordDict[i]) : wordDict[i];
                backtrack(ans, newtmp, wordDict, s, start+len);
            }
        }
    }
};
