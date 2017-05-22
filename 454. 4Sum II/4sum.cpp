class Solution {
public:
    map<int, int> parseArr(vector<int>& A) {
        std::map<int, int> hashmapA;
        for (int i = 0; i < A.size(); i++) {
            if (hashmapA.find(A[i]) != hashmapA.end()) {
                hashmapA[A[i]]++;
            } else {
                hashmapA.insert(std::pair<int, int>(A[i], 1));
            }
        }  
        return hashmapA;
    }
    
    map<int, int> allSums(map<int, int> A, map<int, int> B) {
        std::map<int, int> sums;
        std::map<int, int>::iterator ita = A.begin();
        for (; ita != A.end(); ita++) {
            std::map<int, int>::iterator itb = B.begin();
            for (; itb != B.end(); itb++) {
                int sumab = ita->first + itb->first;
                int combnum = ita->second * itb->second;
                if (sums.find(sumab) != sums.end()) {
                    sums[sumab] += combnum;
                } else {
                    sums.insert(std::pair<int, int>(sumab, combnum));
                }
            }
        }
        return sums;
    }
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::map<int, int> mapA = parseArr(A);
        std::map<int, int> mapB = parseArr(B);
        std::map<int, int> sum1 = allSums(mapA, mapB);
        std::map<int, int> mapC = parseArr(C);
        std::map<int, int> mapD = parseArr(D);
        std::map<int, int> sum2 = allSums(mapC, mapD);
        std::map<int, int>::iterator it1 = sum1.begin();
        int res = 0;
        for (; it1 != sum1.end(); it1++) {
            int target = 0-it1->first;
            if (sum2.find(target) != sum2.end()) {
                res += it1->second * sum2[target];
            }
        }
        return res;
    }
};