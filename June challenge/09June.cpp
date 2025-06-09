// 52. N-Queens II
class Solution
{
public:
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void nQueen(vector<string> &board, int row, int n, int &result)
    {
        if (row == n)
        {
            result++;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (isSafe(board, row, j, n))
            {
                board[row][j] = 'Q';
                nQueen(board, row + 1, n, result);
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        int result = 0;
        nQueen(board, 0, n, result);
        return result;
    }
};