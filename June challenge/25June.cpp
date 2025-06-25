// 2040. Kth Smallest Product of Two Sorted Arrays
class Solution
{
public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        // Step 1: Always use smaller array as outer loop for optimization
        if (nums1.size() > nums2.size())
        {
            return kthSmallestProduct(nums2, nums1, k);
        }

        // Step 2: Define binary search range for possible products
        long long lo = -1e10;
        long long hi = 1e10;

        // Step 3: Binary search for the smallest product such that
        // at least k pairs (nums1[i] * nums2[j]) are <= that product
        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            long long cnt = countLE(mid, nums1, nums2);

            if (cnt < k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        // Step 4: Return the kth smallest product
        return lo;
    }

private:
    // Count how many products nums1[i] * nums2[j] are <= x
    long long countLE(long long x, const vector<int> &A, const vector<int> &B)
    {
        long long count = 0;
        int n = B.size();

        if (x >= 0)
        {
            int jPos = n - 1;
            int jNeg = n - 1;

            for (int a : A)
            {
                if (a > 0)
                {
                    while (jPos >= 0 && 1LL * a * B[jPos] > x)
                        jPos--;
                    count += jPos + 1;
                }
                else if (a == 0)
                {
                    count += n; // zero product always <= x if x >= 0
                }
                else // a < 0
                {
                    while (jNeg >= 0 && 1LL * a * B[jNeg] <= x)
                        jNeg--;
                    count += n - 1 - jNeg;
                }
            }
        }
        else // x < 0
        {
            int jPos = 0;
            int jNeg = 0;

            for (int a : A)
            {
                if (a > 0)
                {
                    while (jPos < n && 1LL * a * B[jPos] <= x)
                        jPos++;
                    count += jPos;
                }
                else if (a == 0)
                {
                    continue; // zero products > x (x < 0)
                }
                else // a < 0
                {
                    while (jNeg < n && 1LL * a * B[jNeg] > x)
                        jNeg++;
                    count += n - jNeg;
                }
            }
        }

        return count;
    }
};

// Check if frequencies can be equal

class Solution
{
public:
    bool sameFreq(string &s)
    {
        int Freq[26] = {};
        int num_of_ele = 0;

        for (int i = 0; i < s.size(); i++)
        {
            Freq[s[i] - 'a']++;
        }

        set<int> se;
        for (int i = 0; i < 26; i++)
        {
            if (Freq[i] > 0)
            {
                num_of_ele++;
                se.insert(Freq[i]);
            }
        }

        if (se.size() == 1)
            return true;

        if (se.size() == 2)
        {
            if (*next(se.begin(), 0) == 1 or
                *next(se.begin(), 1) == 1 or
                abs(*next(se.begin(), 0) - *next(se.begin(), 1)) == 0)
            {
                return true;
            }

            if ((abs(*next(se.begin(), 0) - *next(se.begin(), 1)) == 1))
            {
                if (num_of_ele == 2)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            return false;
        }

        return false;
    }
};