//
class Solution
{
public:
    typedef long long ll;

    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        ll lSum = 0;
        int result = INT_MAX;
        int index = -1;

        for (int i = 0; i < n; ++i)
        {
            lSum += nums[i];
            ll rSum = sum - lSum;

            ll lAvg = lSum / (i + 1);
            ll rAvg = (i == n - 1) ? 0 : rSum / (n - i - 1);

            int diff = abs(lAvg - rAvg);
            if (diff < result)
            {
                result = diff;
                index = i;
            }
        }

        return index;
    }
};

// 2389. Longest Subsequence With Limited Sum
class Solution
{
public:
    int binarySearch(vector<int> &nums, int x)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else if (nums[mid] > x)
            {
                high = mid - 1;
            }
        }
        return ans + 1;
    }
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }
        vector<int> result;
        for (int i = 0; i < queries.size(); i++) // queries.size()
        {
            int res = binarySearch(nums, queries[i]); // logn ////upper_bound(nums.begin(), nums.end(), queries[i])-nums.begin()
            result.push_back(res);
        }
        return result;
    }
};
