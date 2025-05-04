// 560. Subarray Sum Equals K
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0, count = 0;
        unordered_map<int, int> um;
        um[0] = 1;

        for (int num : nums)
        {
            sum += num;
            if (um.find(sum - k) != um.end())
            {
                count += um[sum - k];
            }
            um[sum]++;
        }
        return count;
    }
};