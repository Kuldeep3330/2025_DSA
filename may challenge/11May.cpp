// 26. Remove Duplicates from Sorted Array
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int first = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[first] != nums[i])
            {
                first++;
                nums[first] = nums[i];
            }
        }
        //    nums.resize(first+1);
        return first + 1;
    }
};