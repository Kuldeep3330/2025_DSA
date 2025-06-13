// 121. Best Time to Buy and Sell Stock
class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
            else if (prices[i] - buy > profit)
            {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
};

// 2616. Minimize the Maximum Difference of Pairs
class Solution
{
public:
    int n;
    bool possible(vector<int> &nums, int p, int mid)
    {
        int i = 0;
        int countPairs = 0;
        while (i < n - 1)
        {
            if (nums[i + 1] - nums[i] <= mid)
            {
                countPairs++;
                i += 2;
            }
            else
            {
                i++;
            }
        }
        return countPairs >= p;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[n - 1] - nums[0];
        int result = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (possible(nums, p, mid))
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