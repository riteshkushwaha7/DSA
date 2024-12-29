class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int op = 0;
        int row = grid.size(), col = grid[0].size();
        
        for (int i = 0; i < col; i++) { // Iterate through columns
            for (int j = 1; j < row; j++) { // Iterate through rows
                if (grid[j - 1][i] >= grid[j][i]) {
                    int diff = grid[j - 1][i] - grid[j][i] + 1;
                    op += diff;
                    grid[j][i] += diff; // Apply the adjustment
                }
            }
        }
        return op;
    }
};
