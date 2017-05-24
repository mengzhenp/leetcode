class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        std::map<int,int> checkpoints;
        for (int k = 0; k < n-1; k++) {
            checkpoints.insert(std::pair<int, int>(k, 0));
        }
        int row = 0;
        int col = 0;
        for (int i = 0; i < k-1; i++) {
            if (checkpoints[row] < n) {
                checkpoints[row]++;
            }
            //find next number
            int rownext = -1;
            int colnext;
            for (int j = 0; j < n; j++) {
                if (checkpoints[j] < n) {
                    if (rownext == -1) {
                        rownext = j;
                        colnext = checkpoints[j];
                    } else {
                        if (matrix[j][checkpoints[j]] < matrix[rownext][colnext]) {
                            rownext = j;
                            colnext = checkpoints[j];
                        }
                    }
                }            
            }
            row = rownext;
            col = colnext;
            //std::cout << row << " " << col << " " << matrix[row][col] << endl;
        }
        return matrix[row][col];
    }
};