// 1. 169. Majority Element
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[res])
            {
                count++;
            }
            else
            {
                count--;
            }
            if (count == 0)
            {
                res = i;
                count = 1;
            }
        }
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[res] == nums[i])
            {
                count++;
            }
        }
        return (count > n / 2) ? nums[res] : -1;
    }
};

// 53. Maximum Subarray
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            res = max(res, nums[i]);
        }
        return res;
    }
};
// 918. Maximum Sum Circular Subarray
class Solution
{
public:
    int maxSubarraySum(vector<int> &nums)
    {
        int n = nums.size();
        int curr = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i++)
        {
            sum = max(nums[i], sum + nums[i]); /// 1 -1 3 1
            curr = max(curr, sum);             // 1, 3
        }
        return curr;
    }
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int maxSum = maxSubarraySum(nums);
        if (maxSum < 0)
            return maxSum;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            nums[i] = -nums[i];
        }
        int minSum = maxSubarraySum(nums);
        return max(maxSum, sum + minSum);
    }
};