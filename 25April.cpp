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
// Two Sum II
// 3 sum
// Trapping Rain Water
// 3 Sum Closest
// Factorial of Large Numbers
// Next permutation
// Next Permutation
// Rotate Image
// Container With MOst Water
// Spiral Matrix
