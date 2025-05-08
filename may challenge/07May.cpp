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

// 452. Minimum Number of Arrows to Burst Balloons
bool myCmp(vector<int> a, vector<int> b)
{
    return a[1] < b[0];
}
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();
        sort(points.begin(), points.end());
        vector<int> prev = points[0];
        int count = 1;
        for (int curr = 1; curr < n; curr++)
        {
            int currSP = points[curr][0];
            int currEP = points[curr][1];

            int prevSP = prev[0];
            int prevEP = prev[1];

            if (prevEP < currSP) // no overlap
            {
                count++;
                prev = points[curr];
            }
            else
            {
                prev[0] = max(prevSP, currSP);
                prev[1] = min(prevEP, currEP);
            }
        }
        return count;
    }
};

// 1094. Car Pooling
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> highway(1001, 0);
        for (auto &trip : trips)
        {
            int passengers = trip[0], start = trip[1], end = trip[2];
            highway[start] += passengers;
            highway[end] -= passengers;
        }
        if (highway[0] > capacity)
            return false;
        for (int i = 1; i <= 1000; i++)
        {
            highway[i] += highway[i - 1];
            if (highway[i] > capacity)
                return false;
        }
        return true;
    }
};

// 56. Merge Intervals
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        result.push_back(intervals[0]);
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= result.back()[1]) // overlap
            {
                // result.back()[0]=min(result.back()[0],intervals[i][0] );
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

// 3394. Check if Grid can be Cut into Sections
class Solution
{
public:
    int merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < n; i++)
        {
            // overlap
            if (intervals[i][0] < result.back()[1])
            {
                // result.back()[0]=min(result.back()[0],intervals[i][0] );
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result.size();
    }
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        // for x-axis
        vector<vector<int>> hor;

        // for y-axis
        vector<vector<int>> ver;

        for (auto &rectangle : rectangles)
        {
            hor.push_back({rectangle[0], rectangle[2]});
            ver.push_back({rectangle[1], rectangle[3]});
        }
        int horizontalCount = merge(hor);

        int verticalCount = merge(ver);
        if (horizontalCount >= 3 || verticalCount >= 3)
        {
            return true;
        }
        return false;
    }
};