// Sum of all substrings of a number(GFG)

class Solution
{
public:
    int sumSubstrings(string &s)
    {
        // code here
        int n = s.length(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                ans += (stoi(s.substr(i, j - i + 1)));
            }
        }
        return ans;
    }
};

// 2942. Find Words Containing Character
class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> res;
        for (int i = 0; i < words.size(); i++)
        {
            if (count(words[i].begin(), words[i].end(), x))
                res.push_back(i);
        }
        return res;
    }
};