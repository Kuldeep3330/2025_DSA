// 76. Minimum Window Substring
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();

        if (t.length() > n)
            return "";

        unordered_map<char, int> mp;
        for (char &ch : t)
            mp[ch]++;

        int requiredCount = t.length();
        int i = 0, j = 0;

        int windowSize = INT_MAX;
        int start = 0;

        while (j < n)
        {
            char ch = s[j];
            if (mp[ch] > 0)
                requiredCount--;

            mp[ch]--;
            while (requiredCount == 0)
            {
                int currWindowSize = j - i + 1;
                if (windowSize > currWindowSize)
                {
                    windowSize = currWindowSize;
                    start = i;
                }
                mp[s[i]]++;

                if (mp[s[i]] > 0)
                {
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        return windowSize == INT_MAX ? "" : s.substr(start, windowSize);
    }
};

// 199. Binary Tree Right Side View

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        if (root == NULL)
            return ans;
        q.push(root);
        while (1)
        {
            int size = q.size();
            if (size == 0)
                return ans;
            vector<int> data;
            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();
                data.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            ans.push_back(data.back());
        }
    }
};

// 985. Sum of Even Numbers After Queries
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int q = queries.size();
        int evenSum = 0;
        for (int x : nums)
        {
            if (x % 2 == 0)
                evenSum += x;
        }

        // now queries
        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            int val = queries[i][0];
            int idx = queries[i][1];

            if (nums[idx] % 2 == 0)
            {
                evenSum -= nums[idx];
            }
            nums[idx] += val;

            if (nums[idx] % 2 == 0)
            {
                evenSum += nums[idx];
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};

// 334. Increasing Triplet Subsequence
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int num3 = nums[i];
            if (num3 <= num1)
            {
                num1 = num3;
            }
            else if (num3 <= num2)
            {
                num2 = num3;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

// 25. Reverse Nodes in k-Group
#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *curr = head;

        // Count the number of nodes in the list
        int count = 0;
        while (curr)
        {
            count++;
            curr = curr->next;
        }

        // Reverse k nodes at a time
        while (count >= k)
        {
            curr = prev->next;
            ListNode *next = curr->next;

            // Reverse k nodes
            for (int i = 1; i < k; i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            prev = curr;
            count -= k;
        }

        return dummy.next;
    }
};