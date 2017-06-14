class Solution {
public:
    int parse(string a) {
        stringstream s(a);
        int hour;
        int minute;
        char buf;
        s >> hour >> buf >> minute;
        return hour * 60 + minute;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for (int i = 0; i < timePoints.size(); i++) {
            times.push_back(parse(timePoints[i]));
        }
        sort(times.begin(), times.end());
        int maximum = times.back() - times[0];
        if (times[0] == 0) times.push_back(24*60);
        int minimum = 24 * 60;
        for (int i = 0; i < times.size()-1; i++) {
            int temp = times[i+1] - times[i];
            if (temp < minimum) minimum = temp;
        }
        return min(minimum, 24*60-maximum);
    }
};