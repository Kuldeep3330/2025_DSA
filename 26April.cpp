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

// Next Permutation
// Rotate Image
// Container With MOst Water
// Spiral Matrix