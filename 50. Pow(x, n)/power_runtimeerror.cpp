// notice: 2^32 / 2 - 1 : 2147483647


class Solution {
public:
    double myPow(double x, int n) {
        // find sqrt(n) ---- log(n)
        if (n == 0) return 1;
        bool negative = false;
        if (n < 0) {
            n = -n;
            negative = true;
        }
        int low = 0, high = n, mid, root;
        while (high > low) {
            mid = (low + high)/2 + 1;
            if (mid == n/mid) {
                root = mid;
                break;
            }
            if (mid > n/mid) high = n/mid - 1;
            else low = mid;
        }
        root = low;
        // power  O(root*2)
        double partRes = 1;
        for (int i = 0; i < root; i++) {
            partRes *= x;
        }
        double res = 1;
        for (int i = 0; i < root; i++) {
            res *= partRes; 
        }
        int residual = n - root * root;
        for (int i = 0; i < residual; i++) {
            res *= x;
        }
        return negative? 1/res : res;
    }
};