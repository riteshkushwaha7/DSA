



class Solution {
public:
    void combination(vector<int> &candidates, int sum, vector<int> &temp, int index, vector<vector<int>> &ans) {
        if(sum == 0) {
            ans.push_back(temp);
            return;
        }
        if(index == candidates.size() || sum < 0) {
            return;
        }

        temp.push_back(candidates[index]);
        combination(candidates, sum - candidates[index], temp, index, ans);
        
        temp.pop_back();
        combination(candidates, sum, temp, index + 1, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        combination(candidates, target, temp, index, ans);
        return ans;
    }
};
