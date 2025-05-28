
// 74. Search a 2D Matrix
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0, end = m * n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int r = mid / n;
            int c = mid % n;
            if (matrix[r][c] == target)
            {
                return true;
            }
            else if (matrix[r][c] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }
};

// 540. Single Element in a Sorted Array

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            bool isEven;
            if ((high - mid) % 2 == 0)
            {
                isEven = true;
            }
            else
            {
                isEven = false;
            }

            if (nums[mid] == nums[mid + 1])
            {
                if (isEven)
                {
                    low = mid + 2;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                if (isEven)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return nums[high];
    }
};