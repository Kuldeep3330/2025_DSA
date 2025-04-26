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
// Container With MOst Water
// Spiral Matrix