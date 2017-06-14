class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int c = 0, i = a.length()-1, j = b.length()-1;
        while (c == 1 || i >= 0 || j >= 0) {
            c += i >= 0 ? a[i] - '0' : 0;
            c += j >= 0 ? b[j] - '0' : 0;
            if (c%2 == 1) res = "1" + res;
            else res = "0" + res;
            c = c/2;
            i--;
            j--;
        }
        return res;
    }
};