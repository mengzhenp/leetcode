//heap sort -- appropriate unorder examples

class Solution {
public:
    vector<int> insertMinHeap(vector<int>& v, int i) {
        if (v.size() == 1) return v;
        int j = (i-1)/2;
        int temp = v[i];
        while (j >= 0 && i != 0) {
            if (v[j] <= temp) break;
            v[i] = v[j];
            i = j;
            j = (i-1)/2;
        }
        v[i] = temp;
        return v;
    }
    vector<int> buildMinHeap(vector<vector<int>>& matrix) {
        std::vector<int> res;
        int heapsize = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                res.push_back(matrix[i][j]);
                res = insertMinHeap(res, heapsize);
                heapsize++;
            }
        }
        return res;
    }
    vector<int> deleteMinHeap(vector<int> v){
        int temp = v[v.size()-1];
        v[0] = temp; 
        int j = 1;
        int i = (j-1)/2;
        while(j < v.size()) {
            if (j+1 < v.size() && v[j] > v[j+1]) j++;
            if (v[j] > temp) break;
            v[i] = v[j];
            i = j;
            j = i * 2 + 1;
        }
        v[i] = temp;
        v.pop_back();
        return v;
    }
    vector<int> heapSort(vector<int> v) {
        std:vector<int> res;
        while (v.size() > 0) {
            res.push_back(v[0]);
            v = deleteMinHeap(v);            
        }
        return res;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::vector<int> minHeap = buildMinHeap(matrix);
        std::vector<int> sorted = heapSort(minHeap);
        return sorted[k-1];
    }
};