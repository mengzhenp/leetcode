class Solution {
public:
    int getNum(string s, int& i) {
        int n = 0;
        bool negative = false;
        while (s[i] == ' ') i++;
        if (s[i] == '-') {
            i++;
            negative = true;
        } 
        if (s[i] == '+') {
            i++;
        }
        while (s[i] == ' ') i++;
        while (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
            n = n * 10 + s[i] - '0';
            i++;
        }
        while (s[i] == ' ') i++;
        return negative? -n : n;
    }
    
    int calculate(string s) {
        stack<int> nums;
        int i = 0;
        char c;
        while (i < s.size()) {
            c = s[i];
            if (c == ' ') {i++; continue;}
            if (c == '*' || c == '/') {
                i++;
                int n1 = getNum(s, i);
                int n2 = nums.top();
                nums.pop();
                if (c == '*') {
                    nums.push(n1*n2);
                } else {
                    nums.push(n2/n1);
                } 
            } else {
                int n = getNum(s, i);
                nums.push(n);
            }
        }
        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};