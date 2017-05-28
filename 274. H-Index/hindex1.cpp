class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;
        std::vector<int> count;
        for (int i = 0; i <= n; i++) {
            count.push_back(0);
        }
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                std::cout << n << endl;
                count[n]++;    
            } else {
                std::cout << citations[i] << endl;
                count[citations[i]]++;
            }
        }
        int index = 0;

        for (int i = n; i > 0; i--) {
            index += count[i];
            if (index >= i) {
                return i;
            }
        }
        return 0;
    }
};