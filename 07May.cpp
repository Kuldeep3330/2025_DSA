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
