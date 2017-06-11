class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if (n == 0) return 0;
        if (n == 1) return duration;
        int res = duration;
        for (int i = 0; i < n - 1; i++) {
            res += min(timeSeries[i+1] - timeSeries[i], duration);
        }
        return res;
    }
};