// Floyd Warshall(GFG)
void floydWarshall(vector<vector<int>> &grid)
{
    int n = grid.size();
    for (int via = 0; via < n; via++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][via] != 1e8 and grid[via][j] != 1e8)
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
}

// 1523. Count Odd Numbers in an Interval Range
int countOdds(int low, int high)
{
    return ((high + 1) / 2) - (low / 2);
}