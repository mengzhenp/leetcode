/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        std::vector<int> res;
        std::map<int, int> startPointIndex;
        for (int i = 0; i < intervals.size(); i++) {
            startPointIndex[intervals[i].start] = i;
        }
        for (auto iter : intervals) {
            auto it = startPointIndex.lower_bound(iter.end);
            if (it == startPointIndex.end()) res.push_back(-1);
            else res.push_back(it->second);
        }
        return res;
    }
};