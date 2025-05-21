// Kth Smallest Number in Multiplication Table

class Solution
{
public:
    int countElementLessThanMid(int &mid, int m, int n)
    {
        int col = 0;
        int row = m - 1;
        int count = 0;
        while (col < n && row >= 0)
        {
            if ((row + 1) * (col + 1) <= mid)
            {
                count += row + 1;
                col++;
            }
            else
                row--;
        }
        return count;
    }
    int kthSmallest(int m, int n, int k)
    {
        int low = 1;
        int high = m * n;
        while (low < high)
        {
            int mid = (low + high) / 2;
            int count = countElementLessThanMid(mid, m, n);
            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

// 3024. Type of Triangle
class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        set<int> s(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        if ((nums[0] + nums[1]) <= nums[2])
            return "none";
        if (s.size() == 1)
            return "equilateral";
        if (s.size() == 2)
            return "isosceles";
        return "scalene";
    }
};