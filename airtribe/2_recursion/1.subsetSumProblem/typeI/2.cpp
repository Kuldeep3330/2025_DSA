#include <bits/stdc++.h>
using namespace std;

// Subset sum problem
bool helper(vector<int> &v, int sum, int i, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return true;
    }
    if (i == v.size())
    {
        return false;
    }
    if (dp[i][sum] != -1)
        return dp[i][sum];
    bool pick = false;
    if (v[i] <= sum)
    {
        pick = helper(v, sum - v[i], i + 1, dp);
    }

    bool notPick = helper(v, sum, i + 1, dp);

    return dp[i][sum] = pick || notPick;
}

// tabulation
bool helper_2(vector<int> &v, int sum)
{
    int n = v.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (v[0] <= sum)
        dp[0][v[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool pick = false;
            if (v[i] <= j)
            {
                pick = dp[i - 1][j - v[i]];
            }
            bool notPick = dp[i - 1][j];
            dp[i][j] = pick || notPick;
        }
    }
    return dp[n - 1][sum];
}

// tabulation

bool helper_3(vector<int> &v, int sum)
{
    int n = v.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool pick = false;
            if (v[i] <= j)
            {
                pick = dp[i - 1][j - v[i]];
            }
            bool notPick = dp[i - 1][j];
            dp[i][j] = pick || notPick;
        }
    }
    return dp[n][sum];
}

// optimized space complexity
bool helper_4(vector<int> &v, int sum)
{
    int n = v.size();
    vector<vector<bool>> dp(2, vector<bool>(sum + 1, false));
    dp[0][0] = true; // Sum 0 is always possible with empty subset

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            bool pick = false;
            if (v[i] <= j)
            {
                pick = dp[0][j - v[i]];
            }
            bool notPick = dp[0][j];
            dp[1][j] = pick || notPick;
        }

        dp[0] = dp[1]; // Copy current row to previous for next iteration
    }
    return dp[1][sum];
}

// super Optimised

bool helper_5(vector<int> &v, int sum)
{
    int n = v.size();
    vector<bool> dp(sum + 1, false);
    dp[0] = true; // Sum 0 is always possible with empty subset

    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= 0; j--)
        {
            bool pick = false;
            if (v[i] <= j)
            {
                pick = dp[j - v[i]];
            }
            bool notPick = dp[j];
            dp[j] = pick || notPick;
        }
    }
    return dp[sum];
}

int main()
{
    vector<int> v = {2, 7, 4, 5, 19};
    int sum = 12;

    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    if (helper_5(v, sum))
    {
        cout << "sum exists\n";
    }
    else
    {
        cout << "not exists\n";
    }
    return 0;
}
