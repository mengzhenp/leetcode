class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        map<int, int> nummap;
        for (int i = 0; i < nums.size(); i++) {
            if (nummap.find(nums[i]) == nummap.end()) {
                nummap.insert(pair<int, int>(nums[i], 1));
            } else {
                nummap[nums[i]]++;
            }
        }
        int res = 0;
        map<int, int>::iterator it;
        if (k == 0) {
            for (it = nummap.begin(); it != nummap.end(); it++) {
                res += it->second > 1 ? 1 : 0;
            }  
        } else {
            for (it = nummap.begin(); it != nummap.end(); it++) {
                if (nummap.find(it->first + k) != nummap.end()) res += 1;
            }
        }
        return res;
    }
};