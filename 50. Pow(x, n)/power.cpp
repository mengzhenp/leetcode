//logn >>
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 0) return 0;
        unsigned long long num;
        if (n < 0) {
            x = 1/x;
            num = -n;
        } else {
            num = n;
        }
        double ans = 1;
        while (num) {
            if (num & 1) {
                ans *= x;
            } 
            x *= x;
            num >>= 1;
        }
        return ans;
    }
};