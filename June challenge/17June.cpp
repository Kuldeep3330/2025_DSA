// Coin Piles

class Solution
{
public:
    int minimumCoins(vector<int> &arr, int k)
    {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size(), ans = INT_MAX;
        vector<int> pre(n + 1, 0);

        for (int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] + arr[i - 1];

        for (int i = 0; i < n; ++i)
        {
            int high = arr[i] + k;
            int ub = upper_bound(arr.begin(), arr.end(), high) - arr.begin();
            int cost = pre[i] + (pre[n] - pre[ub]) - (n - ub) * high;
            ans = min(ans, cost);
        }
        return ans;
    }
};

// 42. Trapping Rain Water
class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> lMax(n);
        lMax[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            lMax[i] = max(lMax[i - 1], arr[i]);
        }

        vector<int> rMax(n);
        rMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rMax[i] = max(rMax[i + 1], arr[i]);
        }

        int totalWater = 0;
        for (int i = 1; i < n - 1; i++)
        {
            totalWater += min(lMax[i], rMax[i]) - arr[i];
        }
        return totalWater;
    }
};
