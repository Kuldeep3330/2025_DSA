// 2099. Find Subsequence of Length K With the Largest Sum
class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<pair<int, int>> numIndex;
        for (int i = 0; i < nums.size(); i++)
        {
            numIndex.push_back({nums[i], i});
        }

        // Sort in descending order by value
        sort(numIndex.begin(), numIndex.end(), greater<>());

        // Take top k elements
        vector<pair<int, int>> topK(numIndex.begin(), numIndex.begin() + k);

        // Sort top k by original index to maintain order
        sort(topK.begin(), topK.end(), [](auto &a, auto &b)
             { return a.second < b.second; });

        vector<int> result;
        for (auto &p : topK)
        {
            result.push_back(p.first);
        }
        return result;
    }
};