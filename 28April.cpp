// 1. Maximum sum of Non-adjacent nodes(GFG)
class Solution
{
public:
    pair<int, int> a(Node *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }

        pair<int, int> l = a(root->left);
        pair<int, int> r = a(root->right);

        int in = root->data + l.second + r.second;
        int ex = max(l.first, l.second) + max(r.first, r.second);

        return {in, ex};
    }
    int getMaxSum(Node *root)
    {
        // Add your code here
        pair<int, int> akshu = a(root);
        return max(akshu.first, akshu.second);
    }
};

// 985. Sum of Even Numbers After Queries
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> result;
        int evenSum = 0;
        for (int num : nums)
        {
            if (num % 2 == 0)
            {
                evenSum += num;
            }
        }

        for (auto &query : queries)
        {
            int val = query[0];
            int index = query[1];
            if (nums[index] % 2 == 0)
            {
                evenSum -= nums[index];
            }

            nums[index] += val;
            if (nums[index] % 2 == 0)
            {
                evenSum += nums[index];
            }

            result.push_back(evenSum);
        }

        return result;
    }
};

// 2149. Rearrange Array Elements by Sign
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        int even = 0;
        int odd = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                ans[even] = arr[i];
                even += 2;
            }
            else
            {
                ans[odd] = arr[i];
                odd += 2;
            }
        }
        return ans;
    }
};

// Array Leaders
vector<int> leaders(vector<int> &arr)
{
    // Code here
    int n = arr.size();
    vector<int> leaders;
    leaders.push_back(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= leaders.back())
        {
            leaders.push_back(arr[i]);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}
