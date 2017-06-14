class Solution {
public:
    int myAtoi(string str) {
        int l = str.length();
        int num = 0;
        bool negative = false;
        int i = 0;
        while(str[i] == ' ') i++;
        if (str[i] == '+' || str[i] == '-') {
            negative = str[i] == '-';
            i++;
        }
        char c;
        for(; i < l; i++) {
            c = str[i];
            if (c - '0' <= 9 && c - '0' >= 0) {
                if (num > 214748364) return negative ? -2147483648 : 2147483647;
                if (negative && num * 10 >= 2147483648 - (c-'0')) return -2147483648;
                if (!negative && num * 10 >= 2147483647 - (c-'0')) return 2147483647;
                num = num * 10 + c-'0';
            } else {
                break;
            }
        }
        return negative? -num : num;
    }
};