class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int front=1, back=1;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            front *= nums[i];
            back *= nums[nums.size()-1-i];
            ans = max(ans, max(front, back));
            front = front == 0 ? 1 : front;
            back = back == 0? 1 : back;
        }
        return ans;
    }
};