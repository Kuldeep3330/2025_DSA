// 509. Fibonacci Number(memoization)
class Solution
{
public:
    int helper(int n, vector<int> &dp)
    {
        if (dp[n] != -1)
        {
            return dp[n];
        }
        if (n <= 1)
        {
            dp[n] = n;
            return dp[n];
        }
        dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
        return dp[n];
    }

    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    };
    //
    class Solution
    {
    public:
        int fib(int n)
        {
            if (n <= 1)
                return n;
            vector<int> dp(n + 1);
            dp[0] = 0;
            dp[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
    };