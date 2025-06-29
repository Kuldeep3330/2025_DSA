// 1498. Number of Subsequences That Satisfy the Given Sum Condition
class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++)
        {
            power[i] = (power[i - 1] * 2) % MOD;
        }
        int l = 0, r = n - 1;
        int result = 0;
        while (l <= r)
        {
            if (nums[l] + nums[r] <= target)
            {
                result = (result + power[r - l]) % MOD;
                l++;
            }
            else
            {
                r--;
            }
        }
        return result;
    }
};