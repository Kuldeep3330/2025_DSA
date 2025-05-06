// 766. Toeplitz Matrix
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (mat[i][j] != mat[i - 1][j - 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// 1706. Where Will the Ball Fall

class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result;
        for (int ball = 0; ball < n; ball++)
        {

            int row = 0, col = ball;
            bool stuck = false;
            while (row < m && col < n)
            {
                if (grid[row][col] == 1)
                {
                    if (col == n - 1 || grid[row][col + 1] == -1)
                    {
                        stuck = true;
                        break;
                    }
                    col++;
                }
                else
                {
                    if (col == 0 || grid[row][col - 1] == 1)
                    {
                        stuck = true;
                        break;
                    }
                    col--;
                }
                row++;
            }
            result.push_back(stuck ? -1 : col);
        }
        return result;
    }
};