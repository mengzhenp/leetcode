class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int low = 0, high = x, mid;
        while (high > low) {
            mid = (low + high)/2 + 1;
            if (mid * mid <= x && mid * mid > x) return mid;
            if (mid <= x/mid) {
                low = mid;
                high = min(high, x/mid);
            }
            else {
                high = mid - 1;
            }
            //std::cout << high << " " << low << endl;
        }
        return low;
    }
};