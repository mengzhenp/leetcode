#include <algorithm> sort

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.size() == 0) return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int res = 0;
        int j = 0;
        for (int i = 0; i < houses.size(); i++) {
            for (; j < heaters.size()-1; j++) {
                if (abs(heaters[j+1] - houses[i]) > abs(heaters[j] - houses[i])) break;
            }
            if (res < abs(heaters[j] - houses[i])) res = abs(heaters[j] - houses[i]);
        }
        return res;
    }
};