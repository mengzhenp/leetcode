// mid = low + (high - low)/2; faster than (low + high)/2

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int mid;
        bool previous;
        bool middle;
        bool later;
        while (high > low) {
            mid = low + (high - low)/2;
            if (isBadVersion(mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};