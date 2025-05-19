// 930. Binary Subarrays With Sum
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int result = 0;
        int currSum = 0;
        mp[0] = 1;
        for (int &num : nums)
        {
            currSum += num;
            int check = currSum - goal;
            if (mp.find(check) != mp.end())
            {
                result += mp[check];
            }
            mp[currSum]++;
        }
        return result;
    }
};

// 713. Subarray Product Less Than K
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k <= 1)
            return 0;
        int i = 0, j = 0, result = 0;
        int prod = 1;
        while (j < n)
        {
            prod *= nums[j];

            while (prod >= k)
            {
                prod /= nums[i];
                i++;
            }
            result += (j - i + 1);
            j++;
        }
        return result;
    }
};