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

// 46. Permutations
class Solution
{
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            helper(nums, ans, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;
        helper(nums, ans, 0);
        return ans;
    }
};

// 47. Permutations II
class Solution
{
public:
    set<vector<int>> s;
    void helper(vector<int> &nums, vector<vector<int>> &ans, int i)
    {
        if (i == nums.size() && !s.count(nums))
        {
            ans.push_back(nums);
            s.insert(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            helper(nums, ans, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        helper(nums, ans, i);
        return ans;
    }
};

//
class Solution
{
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for (int j = i; j < nums.size(); j++)
        {
            if (used.count(nums[j]))
                continue; // Skip duplicates

            used.insert(nums[j]);
            swap(nums[i], nums[j]);
            helper(nums, ans, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        helper(nums, ans, i);
        return ans;
    }
};
