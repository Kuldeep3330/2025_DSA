// Game with String

int minValue(string &s, int k)
{
    // code here
    unordered_map<char, int> mp;

    for (auto i : s)
        mp[i]++;

    vector<int> arr;

    for (auto i : mp)
        arr.push_back(i.second);

    while (k--)
    {
        sort(arr.begin(), arr.end());
        arr[arr.size() - 1]--;
    }
    int sum = 0;
    for (auto i : arr)
    {
        sum += i * i;
    }
    return sum;
}

// 2311. Longest Binary Subsequence Less Than or Equal to K
class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int n = s.size();
        int zeros = 0, ones = 0;
        long long value = 0, pow = 1;

        for (char c : s)
        {
            if (c == '0')
                zeros++;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                if (value + pow > k)
                {
                    continue; // Skip this '1' as it would exceed k
                }
                value += pow;
                ones++;
            }
            pow <<= 1;
            if (pow > k)
                break; // Further bits would exceed k
        }

        return zeros + ones;
    }
};