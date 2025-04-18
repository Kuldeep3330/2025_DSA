int findDuplicate(vector<int> &nums)
{
    // unordered_map<int, int> um;(O(n))
    // bool flag isVisited SC: O(n)
    // TC: O(n*n)

    // heir and tortoise(slow and fast pointer)
    int n = nums.size();
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

    } while (slow != fast);
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}

////238. Product of Array Except Self
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> answer(n, 1);
    int left = 1;
    for (int i = 0; i < n; i++)
    {
        answer[i] = left;
        left *= nums[i];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] *= right;
        right *= nums[i];
    }

    return answer;
}