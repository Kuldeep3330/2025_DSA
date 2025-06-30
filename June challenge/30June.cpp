// 594. Longest Harmonious Subsequence
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int maxa = 0;
        for (int i : nums)
        {
            m[i]++;
        }
        for (int i : nums)
        {
            if (m[i - 1] || m[i + 1])
            {
                maxa = max({maxa, m[i] + m[i - 1], m[i] + m[i + 1]});
            }
        }
        return maxa;
    }
};
// Max min Height(GFG)

class Solution
{
public:
    bool isPossible(vector<int> &arr, int k, int w, int target)
    {
        int n = arr.size();
        vector<int> diff(n + 2, 0);
        long long operations = 0, curr_add = 0;

        for (int i = 0; i < n; i++)
        {
            curr_add += diff[i];
            long long current_height = arr[i] + curr_add;

            if (current_height < target)
            {
                int need = target - current_height;
                operations += need;
                if (operations > k)
                    return false;

                curr_add += need;
                if (i + w < n)
                    diff[i + w] -= need;
            }
        }

        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w)
    {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int answer = low;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, w, mid))
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return answer;
    }
};