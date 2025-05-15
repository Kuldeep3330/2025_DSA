// 219. Contains Duplicate II
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++)
        {
            if (um.find(nums[i]) != um.end())
            {
                if (abs(i - um[nums[i]]) <= k)
                    return true;
            }
            um[nums[i]] = i;
        }
        return false;
    }
};

// 2444. Count Subarrays With Fixed Bounds
class Solution
{
public:
    typedef long long ll;
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();
        ll ans = 0;
        ll minPos = -1;
        ll maxPos = -1;
        ll culpritInd = -1;
        for (int i = 0; i < n; i++)
        {
            if (minK > nums[i] || nums[i] > maxK)
            {
                culpritInd = i;
            }
            if (nums[i] == minK)
            {
                minPos = i;
            }
            if (nums[i] == maxK)
            {
                maxPos = i;
            }
            int smaller = min(minPos, maxPos);
            int temp = smaller - culpritInd;
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};