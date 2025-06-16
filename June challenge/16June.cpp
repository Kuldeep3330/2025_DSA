//
class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int minVal = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > minVal)
            {
                maxDiff = max(maxDiff, nums[i] - minVal);
            }
            else
            {
                minVal = nums[i];
            }
        }

        return maxDiff;
    }
};

// 135. Candy
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left to right pass
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left pass
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int sum = 0;
        for (int c : candies)
            sum += c;
        return sum;
    }
};