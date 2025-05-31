// 2439. Minimize Maximum of Array
class Solution
{
public:
    bool isValid(vector<int> &nums, int mid)
    {
        int n = nums.size();
        vector<long long> arr(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > mid)
                return false;
            long long buffer = mid - arr[i];
            arr[i + 1] = arr[i + 1] - buffer;
        }
        return arr[n - 1] <= mid;
    }
    int minimizeArrayValue(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int high = *max_element(nums.begin(), nums.end());
        int result = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isValid(nums, mid))
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return result;
    }
};

// 1802. Maximum Value at a Given Index in a Bounded Array
class Solution
{
public:
    typedef long long ll;

    ll getSumElements(ll count, ll val)
    {
        return val * count - (count * (count + 1)) / 2;
    }

    int maxValue(int n, int index, int maxSum)
    {
        ll left = 1;
        ll right = maxSum;
        ll mid_val;
        int result = 0;

        while (left <= right)
        {
            mid_val = left + (right - left) / 2;
            ll left_count = min((ll)index, mid_val - 1);
            ll left_sum = getSumElements(left_count, mid_val);
            left_sum += max((ll)0, index - mid_val + 1);

            ll right_count = min((ll)n - index - 1, mid_val - 1);
            ll right_sum = getSumElements(right_count, mid_val);
            right_sum += max((ll)0, n - index - 1 - mid_val + 1);

            if (left_sum + right_sum + mid_val <= maxSum)
            {
                result = max((ll)result, mid_val);
                left = mid_val + 1;
            }
            else
            {
                right = mid_val - 1;
            }
        }
        return result;
    }
};