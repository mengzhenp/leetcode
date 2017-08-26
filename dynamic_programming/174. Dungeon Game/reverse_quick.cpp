class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<int> cur(n, 0);
        for(int i = m - 1; i >= 0; i--)
            for(int j = n - 1; j >= 0; j--){
                if(i == m - 1 && j == n - 1){
                    cur[j] = 1 - dungeon[i][j];
                }else if(i == m - 1){
                    cur[j] = cur[j + 1] - dungeon[i][j];
                }else if(j == n - 1){
                    cur[j] = cur[j] - dungeon[i][j];
                }else{
                    cur[j] = min(cur[j], cur[j + 1]) - dungeon[i][j];
                }
                if(cur[j] <= 0) cur[j] = 1;
            }
        return cur[0];
    }
};