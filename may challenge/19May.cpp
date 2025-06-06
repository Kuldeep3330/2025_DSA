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

// 2958. Length of Longest Subarray With at Most K Frequency
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0, result = 0;
        while (j < n)
        {
            mp[nums[j]]++;

            while (i < j && mp[nums[j]] > k)
            {
                mp[nums[i]]--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};

// 2962. Count Subarrays Where Max Element Appears at Least K Times
class Solution
{
public:
    typedef long long ll;
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxE = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = 0;
        ll result = 0;
        int countMax = 0;
        while (j < n)
        {
            if (nums[j] == maxE)
            {
                countMax++;
            }
            while (countMax >= k)
            {
                result += n - j;
                if (nums[i] == maxE)
                {
                    countMax--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};