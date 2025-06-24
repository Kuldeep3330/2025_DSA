// 2200. Find All K-Distant Indices in an Array
class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> index;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (nums[j] == key && abs(i - j) <= k)
                {
                    index.push_back(i);
                    break;
                }
            }
        }
        return index;
    }
};

// Lexicographically Largest String After K Deletions

class Solution
{
public:
    string maxSubseq(string &s, int k)
    {
        // code here
        stack<int> st;
        int n = s.length();
        int cnt = 0; // To keep track on number of elements present in the stack at any point of time
        for (int i = 0; i < n; i++)
        {
            while (cnt > (i - k) && !st.empty() && s[st.top()] < s[i])
            {
                // cnt>(i-k) ensure that we dont run into shortage of characters
                cnt--;
                st.pop();
            }
            if (cnt < (n - k))
            {
                st.push(i); // Add current character if stack has less than n-k characters
                cnt++;
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans.push_back(s[st.top()]);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};