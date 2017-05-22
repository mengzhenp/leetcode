class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0) return {};
        std::map<int, int> map1;
        for (int i = 0; i < nums1.size(); i++) {
            if (map1.find(nums1[i]) != map1.end()) {
                map1[nums1[i]]++;
            } else {
                map1.insert(pair<int, int>(nums1[i], 1));
            }
        }
        std::vector<int> res;
        for (int j = 0; j < nums2.size(); j++) {
            if (map1.find(nums2[j]) != map1.end()) {
                res.push_back(nums2[j]);
                map1.erase(nums2[j]);
            }
        }
        return res;
    }
};