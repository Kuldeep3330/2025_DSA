// Minimum Deletions(GFG)
class Solution
{
public:
    int dp[1001][1001];
    int rec(int i, int j, string &s)
    {
        if (i == j || i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 1e9;
        if (s[i] != s[j])
        {
            ans = min(ans, rec(i + 1, j, s) + 1);
            ans = min(ans, rec(i, j - 1, s) + 1);
        }
        else
        {
            ans = min(ans, rec(i + 1, j - 1, s));
        }
        return dp[i][j] = ans;
    }
    int minDeletions(string s)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        // cout<<n<<" ";
        int ans = rec((int)0, n - 1, s);
        return ans;
    }
};