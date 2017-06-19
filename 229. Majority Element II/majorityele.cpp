class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return nums;
        if (n == 2 && nums[0] == nums[1]) return {nums[0]};
        if (n == 2) return nums;
        int upper = n/3;
        int num1 = nums[0], num2 = nums[0], count1 = 1, count2 = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == num1) count1++;
            else if (nums[i] == num2) count2++;
            else if (count1 == 0) {num1 = nums[i]; count1 = 1;}
            else if (count2 == 0) {num2 = nums[i]; count2 = 1;}
            else {count1--; count2--;}
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == num1) {
                if (count1 == 0 && count2 > 0) {
                    swap(num1, num2);
                    swap(count1, count2);
                    count2++;
                }
                else count1++;
            }
            else if (nums[i] == num2) count2++;
        }
        //cout << num1 << " " << count1 << endl;
        //cout << num2 << " " << count2 << endl;
        if (count1 > upper) res.push_back(num1);
        if (num1 != num2 && count2 > upper) res.push_back(num2);
        return res;
    }
};