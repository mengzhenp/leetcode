//with the principle of heap sort
//with ordered matrix but still runtime error

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        for (int i = 0; i < k-1; i++) {
            int temp = matrix.back().back();
            matrix[0][0] = temp;
            matrix.back().pop_back();
            if (matrix.back().size() == 0) matrix.pop_back();
            int col = 0;
            while (col < matrix[0].size()-1) {
                col++;
                if (temp < matrix[0][col]) {
                    col--;
                    break;
                }
                if (temp >= matrix[0][col]) {
                    matrix[0][col-1] = matrix[0][col];
                }
            }
            matrix[0][col] = temp;
            std::vector<int> tempv;
            for (int k = 0; k < matrix[0].size(); k++) {
                tempv.push_back(matrix[0][k]);
            }
            int row = 0;
            while (row < matrix.size()-1) {
                row++;
                if (tempv[0] < matrix[row][0]) {
                    row--;
                    break;
                }
                if (tempv[0] >= matrix[row][0]) {
                    matrix[row-1].clear(); 
                    for (int k = 0; k < matrix[row].size(); k++) {
                        matrix[row-1].push_back(matrix[row][k]);
                    }
                }
            }
            matrix[row].clear();
            for (int k = 0; k < tempv.size(); k++) {
                matrix[row].push_back(tempv[k]);
            }
            //-----
            //for (int l = 0; l < matrix.size(); l++) {
                //for (int m = 0; m < matrix[l].size(); m++) {
                   // std::cout << matrix[l][m] << " ";
                //}
                //std::cout << endl;
            //}
            //-----
        }
        return matrix[0][0];
    }
};