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