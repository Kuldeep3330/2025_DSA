// 1. Two Sum
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            int diff = target - nums[i];
            if (um.find(diff) != um.end())
            {
                return {um[diff], i};
            }
            um[nums[i]] = i;
        }
        return {};
    }
};
// 167. Two Sum II - Input Array Is Sorted
class Solution
{
public:
    vector<int> twoSum(vector<int> &arr, int target)
    {
        // sorted arr two pointer approach
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int sum = arr[low] + arr[high];
            if (sum == target)
            {
                return {low + 1, high + 1};
            }
            else if (sum > target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return {};
    }
};
// 3 sum
// Trapping Rain Water
// 3 Sum Closest
// Factorial of Large Numbers
// Next permutation
// Next Permutation
// Rotate Image
// Container With MOst Water
// Spiral Matrix
