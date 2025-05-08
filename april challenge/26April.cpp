// 31. Next Permutation
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int pivot = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i + 1] > nums[i])
        {
            pivot = i;
            break;
        }
    }
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    int second = -1;
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] > nums[pivot])
        {
            second = i;
            break;
        }
    }
    swap(nums[pivot], nums[second]);
    reverse(nums.begin() + pivot + 1, nums.end());
}

// 48. Rotate Image
void rotate(vector<vector<int>> &mat)
{
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // reverse all rows
    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}
// 11. Container With Most Water
class Solution
{
public:
    int maxArea(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int maxArea = INT_MIN;
        while (low < high)
        {
            int height = min(arr[low], arr[high]);
            int width = high - low;
            maxArea = max(maxArea, height * width);
            if (arr[low] < arr[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return maxArea;
    }
};
// 54. Spiral Matrix
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        vector<int> result;
        int top = 0, left = 0, bottom = r - 1, right = c - 1;
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
                // cout << mat[top][i] << " ";
                result.push_back(mat[top][i]);
            top++;
            for (int i = top; i <= bottom; i++)
                // cout << mat[i][right] << " ";
                result.push_back(mat[i][right]);
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    // cout << mat[bottom][i] << " ";
                    result.push_back(mat[bottom][i]);
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    // cout << mat[i][left] << " ";
                    result.push_back(mat[i][left]);
                left++;
            }
        }
        return result;
    }
};