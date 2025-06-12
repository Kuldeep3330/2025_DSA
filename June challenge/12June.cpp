// Unique Paths in a Grid
class Solution
{
public:
    int helper(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (grid[i][j] == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = 0, right = 0;

        if (i + 1 < m)
            down = helper(grid, i + 1, j, m, n, dp);
        if (j + 1 < n)
            right = helper(grid, i, j + 1, m, n, dp);
        return dp[i][j] = down + right;
    }
    int uniquePaths(vector<vector<int>> &grid)
    {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, 0, 0, m, n, dp);
    }
};

// K closest elements

class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int k, int x)
    {
        sort(arr.begin(), arr.end(), [x](const int &a, const int &b)
             {
            if(abs(a-x) == abs(b-x)){
                return a>b;
            }
            return abs(a-x) < abs(b-x); });
        vector<int> ans;
        for (auto it : arr)
        {
            if (it != x)
            {
                ans.push_back(it);
                if (ans.size() == k)
                    return ans;
            }
        }
        return {};
    }
};
// 189. Rotate Array
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        // Step 1: Copy last k elements into temp
        vector<int> temp(k);
        for (int i = 0; i < k; i++)
        {
            temp[i] = nums[n - k + i];
        }

        // Step 2: Shift the remaining elements to the right
        for (int i = n - k - 1; i >= 0; i--)
        {
            nums[i + k] = nums[i];
        }

        // Step 3: Copy temp elements back to front
        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }
    }
};

// 3423. Maximum Difference Between Adjacent Elements in a Circular Array
class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        const int n = nums.size();
        int ans = abs(nums[0] - nums[n - 1]);
        for (int i = 1; i < n; i++)
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        return ans;
    }
};