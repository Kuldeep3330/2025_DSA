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