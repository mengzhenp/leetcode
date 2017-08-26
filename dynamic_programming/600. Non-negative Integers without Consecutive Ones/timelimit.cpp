class Solution {
public:
    int findIntegers(int num) {
        int cur = 0;
        int ans = 0;
        while(cur <= num) {
            if(isValid(cur)) ans += 1;
            cur += 1;
        }
        return ans;
    }
private:
    bool isValid(int num) {
        int pre = 1 & num;
        int cur;
        num >>= 1;
        while(num > 0) {
            cur = 1 & num;
            if(cur == 1 && pre == 1) return false;
            pre = cur;
            num >>= 1;
        }
        return true;
    }
};