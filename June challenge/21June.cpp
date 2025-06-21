// 1328. Break a Palindrome
class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.length();
        if (n == 1)
            return "";
        for (int i = 0; i < n / 2; i++)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};
// 991. Broken Calculator
class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        if (startValue >= target)
        {
            return startValue - target;
        }
        if (target % 2 == 0)
        {
            return 1 + brokenCalc(startValue, target / 2);
        }
        else
        {
            return 1 + brokenCalc(startValue, target + 1);
        }
    }
};
// 1578. Minimum Time to Make Rope Colorful
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        vector<pair<char, int>> vec;
        for (int i = 0; i < colors.length(); i++)
        {
            vec.push_back({colors[i], neededTime[i]});
        }

        int ans = 0;
        pair<char, int> prev = vec[0];

        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i].first == prev.first)
            {
                ans += min(prev.second, vec[i].second);
                prev.second = max(prev.second, vec[i].second);
            }
            else
            {
                prev = vec[i];
            }
        }

        return ans;
    }
};
