
class Solution {
public:
    void combination(vector<int>& candidates, int sum, vector<int>& temp,
                     int index, vector<vector<int>>& ans, vector<bool>& used) {
        if (sum == 0) {
            ans.push_back(temp);
            return;
        }
        if (index == candidates.size() || sum < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1] &&
                !used[i - 1]) {
                continue;
            }

            if (!used[i]) {
                temp.push_back(candidates[i]);
                used[i] = true;
                combination(candidates, sum - candidates[i], temp, i + 1, ans,
                            used);
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        combination(candidates, target, temp, index, ans, used);
        return ans;
    }
};
