class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationsum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationsum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i];) {
            combination.push_back(candidates[i]);
            combinationsum(candidates, target-candidates[i], res, combination, i+1);
            combination.pop_back();
            i++;
            while(candidates[i] == candidates[i-1]) i++;
        }
    }
};