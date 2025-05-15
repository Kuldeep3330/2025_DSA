// 1493. Longest Subarray of 1's After Deleting One Element
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int zeroCount = 0;
        int maxLen = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            if (nums[j] == 0)
                zeroCount++;
            while (zeroCount > 1)
            {
                if (nums[i] == 0)
                    zeroCount--;
                i++;
            }
            maxLen = max(maxLen, j - i);
            j++;
        }
        return maxLen;
    }
};