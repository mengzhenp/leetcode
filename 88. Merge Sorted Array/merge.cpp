class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        if (n == 0) return;
        while (i < m) {
            if (nums1[i] <= nums2[0]) {
                i++;
            } else {
                int temp = nums1[i];
                nums1[i] = nums2[0];
                nums2[0] = temp;
                if (nums2[1] < temp) {
                    for (int j = 1; j < n; j++) {
                        if (nums2[j] < temp) {
                            nums2[j-1] = nums2[j];
                        } else {
                            nums2[j-1] = temp;
                            break;
                        }
                    }
                }
                if (nums2[n-2] < temp) nums2[n-1] = temp;
            }
        }
        int k = m;
        for(int num:nums2) {
            nums1[m] = num;
            m++;
        }
    }
};