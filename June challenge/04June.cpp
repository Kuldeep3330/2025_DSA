// https://www.geeksforgeeks.org/problems/coin-change2448/1
//  Coin Change (Count Ways)(GFG)
class Solution
{
public:
    int mod = 1e9 + 7;
    int helper(int i, int n, vector<int> &coins, int sum, vector<vector<int>> &dp)
    {
        if (i >= n || sum < 0)
            return 0;
        if (sum == 0)
            return 1;
        if (dp[i][sum] != -1)
            return dp[i][sum];

        int take = helper(i, n, coins, sum - coins[i], dp);
        ;
        int notTake = helper(i + 1, n, coins, sum, dp);

        return dp[i][sum] = (take + notTake);
    }
    int count(vector<int> &coins, int sum)
    {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(0, n, coins, sum, dp);
    }
};
