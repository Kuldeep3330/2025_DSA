// Case-specific Sorting of Strings
class Solution
{
public:
    string caseSort(string &s)
    {
        // code here
        string hi = "", lo = "";
        for (auto x : s)
        {
            if (isupper(x))
                hi += x;
            else
                lo += x;
        }
        sort(hi.begin(), hi.end());
        sort(lo.begin(), lo.end());
        int i = 0, j = 0;
        for (int k = 0; k < s.size(); k++)
        {
            if (isupper(s[k]))
                s[k] = hi[i++];
            else
                s[k] = lo[j++];
        }
        return s;
    }
};
// 43. Multiply Strings

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        vector<int> res(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; i--)
        {
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }

        int i = 0;
        string ans = "";
        while (res[i] == 0)
            i++;
        while (i < res.size())
            ans += to_string(res[i++]);

        return ans;
    }
};
