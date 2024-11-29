



class Solution {
public:
    bool check(int n, vector<string>& board, int i, int j) {
        int row = i, col = j;
        while (row > -1 && col > -1) {
            if (board[row][col] == 'Q')
                return false;

            row--;
            col--;
        }
        row = i, col = j;
        while (row > -1 && col < n) {
            if (board[row][col] == 'Q')
                return false;

            row--;
            col++;
        }
        return true;
    }
    void find(int row, int n, vector<vector<string>>& ans,
              vector<string>& board, vector<bool> column) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (column[j] && check(n, board, row, j)) {
                column[j] = false;
                board[row][j] = 'Q';
                find(row + 1, n, ans, board, column);

                column[j] = true;
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < n; j++)
        //         board[i].push_back('.');

        vector<bool> column(n, true);
        find(0, n, ans, board, column);

        return ans;
    }
};
