class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int l = digits.length();
        if (l == 0) return {};
        vector<string> table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            int num = digits[i] - '0';
            if (num < 2 || num > 9) return {};
            string temp = table[num];
            if (temp.empty()) continue;
            vector<string> tempstr;
            for (int j = 0; j < temp.size(); j++) {
                for (int k = 0; k < res.size(); k++) {
                    tempstr.push_back(res[k] + temp[j]);
                }
            }
            res.swap(tempstr);
        }
        return res;
    }
};