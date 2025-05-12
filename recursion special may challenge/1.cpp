// 78. Subsets
class Solution
{
public:
    void helper(vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        helper(nums, curr, ans, i + 1);

        curr.pop_back();
        helper(nums, curr, ans, i + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, curr, ans, 0);
        return ans;
    }
};

// 90. Subsets II

class Solution
{
public:
    void helper(vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        helper(nums, curr, ans, i + 1);
        curr.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        helper(nums, curr, ans, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        helper(nums, curr, ans, 0);
        return ans;
    }
};