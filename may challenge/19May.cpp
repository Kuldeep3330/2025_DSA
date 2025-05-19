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