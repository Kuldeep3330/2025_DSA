// 75. Sort Colors
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1, i = 0;
        while (i <= high)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[low]);
                i++;
                low++;
            }
            else if (nums[i] == 1)
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[high]);
                high--;
            }
        }
    }
};

// Sort the given array after applying the given equation

class Solution
{
public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            int x = arr[i];
            int res = (A * (x * x)) + (B * x) + C;
            arr[i] = res;
        }
        sort(arr.begin(), arr.end());
        return arr;
    }
};