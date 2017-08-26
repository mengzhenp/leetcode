class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        
        vector<int> ans(k, INT_MIN);
        vector<vector<int>> ans1;
        vector<vector<int>> ans2;
        
        if (k == l1 + l2) {
            merge(ans, nums1, nums2);
            return ans;
        }
        
        maxnum(nums1, ans1);
        maxnum(nums2, ans2);
        
        for(int i = 0; i <= k; i++) {
            if(i <= l1 && k-i <= l2) {
                //cout << "~~~~~~" << i << "~~~~~~~" << endl;
                merge(ans, ans1[i], ans2[k-i]);
            }
        }
        return ans;
    }
private:
    void maxnum(vector<int>& nums, vector<vector<int>>& ans) {
        int checkpos;
        ans.push_back(nums);//the last one
        int len = nums.size()-1;
        while(len > 0) {
            checkpos = 0;
            while(checkpos < ans[0].size()-1 && 
                  ans[0][checkpos] >= ans[0][checkpos+1]) 
                checkpos++;
            //now all the nums are from large to small
            if(checkpos == ans[0].size()-1) {
                vector<int> tmp;
                tmp.insert(tmp.begin(), ans[0].begin(), ans[0].end());
                tmp.pop_back();
                ans.insert(ans.begin(), tmp);
            }
            //we need to check whether there are nums smaller than the next one, then discard it
            else {
                vector<int> tmp;
                tmp.insert(tmp.end(), ans[0].begin(), ans[0].begin()+checkpos);
                tmp.insert(tmp.end(), ans[0].begin()+checkpos+1, ans[0].end());
                ans.insert(ans.begin(), tmp);
            }
            len -= 1;
        }
        ans.insert(ans.begin(), vector<int>());
    }
    
    void merge(vector<int>& ans, vector<int>& ans1, vector<int>& ans2) {
        int l1 = ans1.size();
        int l2 = ans2.size();
        int i = 0, j = 0;
        int pos = 0;
        int tmp;
        bool larger = false;
        while(i < l1 || j < l2) {
            if (i == l1) {
                tmp = ans2[j];
                j += 1;
            } else if (j == l2) {
                tmp = ans1[i];
                i += 1;
            } else {
                if(ans1[i] > ans2[j]) {
                    tmp = ans1[i];
                    i += 1;
                } else if (ans1[i] < ans2[j]){
                    tmp = ans2[j];
                    j += 1;
                } else {
                    //greedy
                    int ii = i;
                    int jj = j;
                    while(ii < l1 && jj < l2 && ans1[ii] == ans2[jj]) {
                        ii += 1;
                        jj += 1;
                    }
                    if (ii == l1) {
                        tmp = ans2[j];
                        j += 1;
                    } else if (jj == l2) {
                        tmp = ans1[i];
                        i += 1;
                    } else if (ans1[ii] > ans2[jj]) {
                        tmp = ans1[i];
                        i += 1;
                    } else {
                        tmp = ans2[j];
                        j += 1;
                    }
                }
            }
            //cout << tmp << endl;
            if(larger) {
                ans[pos] = tmp;
            } else {
                if(tmp < ans[pos]) {
                    return;
                }
                if (tmp > ans[pos]) {
                    larger = true;
                    ans[pos] = tmp;
                }
            }
            pos += 1;
        }
        return;
    }
};