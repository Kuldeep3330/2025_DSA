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
// 8. minimum length of string after deleting similar ends
// 9. maximum width ramp
// 10. partition labels
// 11. push dominoes