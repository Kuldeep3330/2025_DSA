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