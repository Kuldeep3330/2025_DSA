// Dice throw

class Solution
{
public:
    const int MOD = 1000000007;

    int fn(int l, int n, int x, int m, vector<vector<int>> &dp)
    {
        if (n == 0 and x == 0)
            return 1;
        if (n == 0 or x < 0)
            return 0;
        if (dp[n][x] != -1)
            return dp[n][x];
        int ways = 0;
        for (int i = 1; i <= m; i++)
        {
            ways = (ways + fn(i, n - 1, x - i, m, dp)) % MOD;
        }
        return dp[n][x] = ways;
    }
    int noOfWays(int m, int n, int x)
    {

        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= x; j++)
            { // sum or target
                for (int k = 1; k <= m; k++)
                { /// face of dice
                    if (j - k >= 0)
                    {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                    }
                }
            }
        }
        return dp[n][x];
    }
};

// 3068. Find the Maximum Sum of Node Values
class Solution
{
public:
    long long maximumValueSum(vector<int> &v, int k, vector<vector<int>> &edges)
    {
        long long total = accumulate(v.begin(), v.end(), 0ll);

        long long total_diff = 0;
        long long diff;
        int positive_count = 0;
        long long min_abs_diff = numeric_limits<int>::max();
        for (auto p : v)
        {
            diff = (p ^ k) - p;

            if (diff > 0)
            {
                total_diff += diff;
                positive_count++;
            }
            min_abs_diff = min(min_abs_diff, abs(diff));
        }
        if (positive_count % 2 == 1)
        {
            total_diff = total_diff - min_abs_diff;
        }
        return total + total_diff;
    }
};