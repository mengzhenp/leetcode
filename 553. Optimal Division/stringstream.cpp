class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        stringstream ans;
        if (nums.size() == 0) return "";
        if (nums.size() == 1) {
            ans << nums[0];
            return ans.str();
        }
        if (nums.size() == 2) {
            ans << nums[0] << '/' << nums[1];
            return ans.str();
        }
        ans << nums[0] << "/(";
        for (int i = 1; i < nums.size()-1; i++) {
            ans << nums[i] << '/';
        }
        ans << nums[nums.size()-1] << ')';
        return ans.str();
    }
};