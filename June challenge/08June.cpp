// 88. Merge Sorted Array
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int j = 0, i = m; j < n; j++)
        {
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(), nums1.end());
    }
};

// 27. Remove Element
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        nums.erase(
            remove(nums.begin(), nums.end(), val),
            nums.end());
        return nums.size();
    }
};

// 386. Lexicographical Numbers
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<string> s;
        s.reserve(n);

        for (int i = 1; i <= n; i++)
        {
            s.push_back(to_string(i)); // "1", "2", "10", ...
        }
        sort(s.begin(), s.end()); // lexicographically sort

        vector<int> ans;
        ans.reserve(n);
        for (auto &str : s)
        {
            ans.push_back(stoi(str)); // convert back to int
        }
        return ans;
    }
};