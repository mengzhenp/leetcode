class Solution {
public:
    static bool mycmp(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        
        int n = envelopes.size();
        if (n == 0)
            return 0;
        
        sort(envelopes.begin(), envelopes.end(), mycmp);
        
        vector<int> height;
        height.push_back(envelopes[0].second);
        
        for (int i = 1; i < n; ++i) {
            
            auto it = lower_bound(height.begin(), height.end(), envelopes[i].second);
            
            if (it == height.end()) {
                height.push_back(envelopes[i].second);
            }
            else {
                height[it - height.begin()] = envelopes[i].second;
            }
        }
        return height.size();
    }
};
//之前遇到的一个问题是，当有元素的长相等时，前面添加的元素可能会导致后面元素更新height的时候有错，因为假设某个height的元素和要更新的元素长度相等，那么实际是不能更新。  
//通过按长升序，进而宽降序，可避免这个问题。因为如此一来即使长相等，后面出现的元素也不可能更新前面元素所在的位置。