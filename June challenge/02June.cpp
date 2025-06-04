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

    // 198. House Robber(Naive)
    class Solution
    {
    public:
        int helper(vector<int> &nums, int i, int n)
        {

            if (i >= n)
            {
                return 0;
            }
            if (i == n - 1)
                return nums[n - 1];
            // picking
            int take = helper(nums, i + 2, n) + nums[i];
            // not picking
            int notTake = helper(nums, i + 1, n);

            return max(take, notTake);
        }
        int rob(vector<int> &nums)
        {
            int n = nums.size();
            return helper(nums, 0, n);
        }
    };

    // optimised top down memoization
    class Solution
    {
    public:
        int helper(vector<int> &nums, int i, int n, vector<int> &dp)
        {

            if (i >= n)
            {
                return 0;
            }
            if (i == n - 1)
                return dp[i] = nums[n - 1];
            if (dp[i] != -1)
                return dp[i];
            // picking
            int take = helper(nums, i + 2, n, dp) + nums[i];
            // not picking
            int notTake = helper(nums, i + 1, n, dp);

            return dp[i] = max(take, notTake);
        }
        int rob(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> dp(n, -1);
            return helper(nums, 0, n, dp);
        }
    };

    //
    class Solution
    {
    public:
        int rob(vector<int> &nums)
        {
            int n = nums.size();
            if (n == 0)
                return 0;
            if (n == 1)
                return nums[0];

            vector<int> dp(n);
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            for (int i = 2; i < n; i++)
            {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
            return dp[n - 1];
        }
    };