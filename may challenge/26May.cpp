// 37. Sudoku Solver
class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char digit)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == digit)
                return false;
        }

        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == digit)
                return false;
        }

        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;

        for (int i = sr; i < sr + 3; i++)
        {
            for (int j = sc; j < sc + 3; j++)
            {
                if (board[i][j] == digit)
                    return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>> &board, int row, int col)
    {
        if (row == 9)
            return true;

        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9)
        {
            nextRow = row + 1;
            nextCol = 0;
        }

        if (board[row][col] != '.')
        {
            return helper(board, nextRow, nextCol);
        }

        for (char digit = '1'; digit <= '9'; digit++)
        {
            if (isSafe(board, row, col, digit))
            {
                board[row][col] = digit;
                if (helper(board, nextRow, nextCol))
                    return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        helper(board, 0, 0);
    }
};

// Rat in a Maze Problem - I(GFG)

class Solution
{
public:
    void helper(vector<vector<int>> &maze, int row, int col, string path, vector<string> &ans, vector<vector<bool>> &vis)
    {
        int n = maze.size();
        if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || vis[row][col])
        {
            return;
        }

        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(path);
            return;
        }

        vis[row][col] = true;

        helper(maze, row + 1, col, path + "D", ans, vis); // Down
        helper(maze, row - 1, col, path + "U", ans, vis); // Up
        helper(maze, row, col - 1, path + "L", ans, vis); // Left
        helper(maze, row, col + 1, path + "R", ans, vis); // Right

        vis[row][col] = false; // Backtrack
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<string> ans;

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        helper(maze, 0, 0, "", ans, vis);
        sort(ans.begin(), ans.end());

        return ans;
    }
};