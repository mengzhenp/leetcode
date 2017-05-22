class Solution {
public:
    int findNum(vector<int>& numbers, int target, int low) {
        if (target < numbers[low] || target > numbers.back()) return -1;
        int high = numbers.size()-1;
        int mid;
        if (target == numbers[low]) return low;
        if (target == numbers[high]) return high;
        while (high - low > 1) {
            mid = (high + low)/2;
            std::cout << mid << endl;
            if (numbers[mid] == target) return mid;
            if (numbers[mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return -1;     
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> inds;
        int residual;
        int num1;
        for (int i = 0; i < numbers.size()-1;) {
            num1 = numbers[i];
            residual = target - num1;
            if (residual == num1 && numbers[i+1] == num1) return {i+1, i+2};
            if (residual < numbers[i]) return {};
            int j = i;
            for (j; j < numbers.size()-1;j++) {
                if (numbers[j] != num1) {
                    break;
                } 
            }
            int ind2 = findNum(numbers, residual,j);
            if (ind2 > -1) {
                inds.push_back(i+1);
                inds.push_back(ind2+1);
                return inds;
            }
            i = j;
        } 
        return {};
    }
};
