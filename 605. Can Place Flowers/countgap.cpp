class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int l = flowerbed.size();
        if (l == 0) return false;
        int left = -1;
        int right = 0;
        int gap = 1;
        while (right < l && n > 0) {
            if (flowerbed[right] == 0) {
                gap++;
                right++;
            } else {
                n -= (gap-1)/2;
                gap = 0;
                left = right;
                right++;
            }
        }
        gap  = gap + 1;
        n -= (gap-1)/2;
        if (n <= 0) return true;
        return false;
    }
};