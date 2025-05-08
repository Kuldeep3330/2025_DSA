// 2007. Find Original Array From Doubled Array
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int n = changed.size();
        if (n % 2 != 0)
        {
            return {};
        }

        unordered_map<int, int> um;
        sort(changed.begin(), changed.end());
        for (int i = 0; i < n; i++)
        {
            um[changed[i]]++;
        }
        vector<int> result;

        for (int num : changed)
        {
            if (um[num] == 0)
            {
                continue;
            }
            if (um[num * 2] == 0)
            {
                return {};
            }
            result.push_back(num);
            um[num]--;
            um[num * 2]--;
        }
        return result;
    }
};