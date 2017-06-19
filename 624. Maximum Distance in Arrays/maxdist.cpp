class Solution {
public:
    int abs(int a) {
        if (a > 0) return a;
        return -a;
    }
    int max(int a, int b) {
        if (a > b) return a;
        return b;
    }
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        if (n == 0) return 0;
        if (n == 1) {
            if (arrays[0].size() == 0) return 0;
            int temp = arrays[0][arrays[0].size()-1] - arrays[0][0]; 
            return temp;
        } 
        int maxi = 0;
        for (int i = 0; i < n-1; i++) {
            if (arrays[i].size() == 0) continue;
            for (int j = i+1; j < n; j++) {
                if (arrays[j].size() == 0) continue;
                int temp = max(abs(arrays[i][arrays[i].size()-1] - arrays[j][0]), 
                                abs(arrays[i][0] - arrays[j][arrays[j].size()-1]));
                maxi = max(temp, maxi);
            }
        }
        return maxi;
    }
};