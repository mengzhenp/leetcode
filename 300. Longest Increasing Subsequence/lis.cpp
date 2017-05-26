class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) {
                std::cout << nums[i] << endl;
                res.push_back(nums[i]);
            } else {
                std::cout << "else substitute " << *it << " to be " << nums[i] << endl;
                *it = nums[i];
            }
        }
        return res.size();
    }
};