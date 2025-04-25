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
// 15. 3Sum
class Solution
{
public:
    vector<vector<int>> twoSum(vector<int> &nums, int low, int high, int target)
    {
        vector<vector<int>> result;
        while (low < high)
        {
            int sum = nums[low] + nums[high];
            if (sum == target)
            { /// first we will remove dups
                while (low < high && nums[low] == nums[low + 1])
                    low++;
                while (low < high && nums[high] == nums[high - 1])
                    high--;
                result.push_back({-target, nums[low], nums[high]});
                low++;
                high--;
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
        return result;
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            vector<vector<int>> temp = twoSum(nums, i + 1, n - 1, -nums[i]);

            // Append results
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};

// Trapping Rain Water
class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> lMax(n);
        lMax[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            lMax[i] = max(lMax[i - 1], arr[i]);
        }

        vector<int> rMax(n);
        rMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rMax[i] = max(rMax[i + 1], arr[i]);
        }

        int totalWater = 0;
        for (int i = 1; i < n - 1; i++)
        {
            totalWater += min(lMax[i], rMax[i]) - arr[i];
        }
        return totalWater;
    }
};
// 3 Sum Closest
// Factorial of Large Numbers
// Next permutation
// Next Permutation
// Rotate Image
// Container With MOst Water
// Spiral Matrix
