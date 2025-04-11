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