// Mobile numeric keypad

class Solution
{
public:
    int Solve(int x, int y, vector<vector<char>> &num, int n, vector<vector<vector<int>>> &dp)
    {
        if (n == 1)
            return 1;
        if (dp[x][y][n] != -1)
            return dp[x][y][n];
        int ans = 0;
        ans += Solve(x, y, num, n - 1, dp);
        int xaxis[] = {1, 0, -1, 0};
        int yaxis[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int ro = x + xaxis[k];
            int co = y + yaxis[k];
            if (ro >= 0 && ro < 4 && co >= 0 && co < 3 && num[ro][co] != '*')
                ans += Solve(ro, co, num, n - 1, dp);
        }
        return dp[x][y][n] = ans;
    }
    int getCount(int n)
    {
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        vector<vector<char>> num = {{'1', '2', '3'},
                                    {'4', '5', '6'},
                                    {'7', '8', '9'},
                                    {'*', '0', '*'}};

        int ans = 0;
        for (int i = 0; i < num.size(); i++)
        {
            for (int j = 0; j < num[i].size(); j++)
            {
                if (num[i][j] != '*')
                    ans += Solve(i, j, num, n, dp);
            }
        }
        return ans;
    }
};

// 2014. Longest Subsequence Repeated k Times
class Solution
{
public:
    // Checks whether pattern repeated k times is a subsequence of s
    bool solve(string sub, string t, int k)
    {
        int cnt = 0, i = 0;
        for (char ch : t)
        {
            if (ch == sub[i])
            {
                if (++i == sub.size())
                {
                    i = 0;
                    if (++cnt == k)
                        return true;
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k)
    {
        string ans = "";
        queue<string> q;
        q.push("");

        while (!q.empty())
        {
            string curr = q.front();
            q.pop();
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                string next = curr + ch;
                if (solve(next, s, k))
                {
                    ans = next;
                    q.push(next);
                }
            }
        }
        return ans;
    }
};