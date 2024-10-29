class Solution {
public:
    vector<int> next(const vector<int>& previous) {
        vector<int> ans;
        ans.push_back(1);  
        for(int i = 1; i < previous.size(); i++) {
            ans.push_back(previous[i-1] + previous[i]);  
        }
        ans.push_back(1);  
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> initial(1, 1);  

        ans.push_back(initial);

        for(int i = 1; i < numRows; i++) {
            initial = next(initial); 
            ans.push_back(initial);
        }

        return ans;
    }
};
