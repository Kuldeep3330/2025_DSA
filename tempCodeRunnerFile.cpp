#include <bits/stdc++.h>
using namespace std;

int subsetsWithDup(vector<int> &nums)
{
    int j = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[j])
        {
            nums[++j] = nums[i];
        }
    }
    nums.resize(j + 1);
}
int main()
{

    vector<int> nums = {1, 2, 2};
    int ans = subsetsWithDup(nums);
    cout << ans << endl;
    return 0;
}