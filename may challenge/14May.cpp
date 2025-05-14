// 2963. Count the Number of Good Partitions
class Solution
{
public:
    int MOD = 1e9 + 7;
    int numberOfGoodPartitions(vector<int> &nums)
    {
        unordered_map<int, int> um;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            um[nums[i]] = i;
        }
        int result = 1;
        int i = 0;
        int j = 0;
        j = max(j, um[nums[0]]);
        while (i < n)
        {
            if (i > j)
            {
                result = (result * 2) % MOD;
            }
            j = max(j, um[nums[i]]);
            i++;
        }
        return result;
    }
};
// 8. 1750. Minimum Length of String After Deleting Similar Ends
class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i < j && s[i] == s[j])
        {
            char ch = s[i];
            while (i < j && s[i] == ch)
                i++;
            while (j >= i && s[j] == ch)
                j--;
        }
        return j - i + 1;
    }
};
// 9. maximum width ramp
// 10. partition labels
// 11. push dominoes

/////////////SLIDING WINDOW/////////////////
// Count Occurences of Anagrams(GFG)
class Solution
{
public:
    bool allZeroes(vector<int> &count)
    {
        for (auto &cnt : count)
        {
            if (cnt != 0)
                return false;
        }
        return true;
    }
    int search(string &pat, string &txt)
    {
        // code here
        vector<int> count(26, 0);
        for (int i = 0; i < pat.length(); i++)
        {
            count[pat[i] - 'a']++;
        }
        int i = 0, j = 0, result = 0;
        int k = pat.length();
        while (j < txt.length())
        {

            count[txt[j] - 'a']--;

            if (j - i + 1 == k)
            {
                if (allZeroes(count))
                {
                    result++;
                }
                count[txt[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};

// 438. Find All Anagrams in a String
class Solution
{
public:
    bool allZeroes(vector<int> &count)
    {
        for (int cnt : count)
        {
            if (cnt != 0)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        vector<int> count(26, 0);
        for (int i = 0; i < p.length(); i++)
        {
            count[p[i] - 'a']++;
        }

        int i = 0, j = 0;
        int k = p.length();
        while (j < s.length())
        {
            count[s[j] - 'a']--;
            if (j - i + 1 == k)
            {
                if (allZeroes(count))
                {
                    result.push_back(i);
                }
                count[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};

// 209. Minimum Size Subarray Sum
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size(), i = 0, j = 0, minLength = INT_MAX;
        int preSum = 0;
        while (j < n)
        {
            preSum += nums[j];
            while (preSum >= target)
            {
                minLength = min(minLength, j - i + 1);
                preSum -= nums[i];
                i++;
            }
            j++;
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};

// First negative in every window of size k

class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        // write code here
        vector<int> result;
        deque<int> dq;
        int n = arr.size();
        int i = 0, j = 0;

        while (j < n)
        {
            if (arr[j] < 0)
            {
                dq.push_back(arr[j]);
            }
            if (j - i + 1 == k)
            {
                if (!dq.empty())
                {
                    result.push_back(dq.front());
                }
                else
                {
                    result.push_back(0);
                }

                // window shift krni hai
                if (arr[i] < 0 && !dq.empty())
                {
                    dq.pop_front();
                }
                i++;
            }

            j++;
        }

        return result;
    }
};

// 76. Minimum Window Substring
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.length() > s.length())
            return "";
        unordered_map<char, int> um;
        for (char &ch : t)
            um[ch]++;

        int requiredCount = t.length();
        int i = 0, j = 0, start = 0;
        int windowSize = INT_MAX;
        while (j < s.length())
        {
            char ch = s[j];

            if (um[ch] > 0)
                requiredCount--;

            um[ch]--;

            while (requiredCount == 0)
            {
                int currSize = j - i + 1;
                if (windowSize > currSize)
                {
                    windowSize = currSize;
                    start = i;
                }
                um[s[i]]++;
                if (um[s[i]] > 0)
                {
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        return windowSize == INT_MAX ? "" : s.substr(start, windowSize);
    }
};