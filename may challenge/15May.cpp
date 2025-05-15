// 219. Contains Duplicate II
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++)
        {
            if (um.find(nums[i]) != um.end())
            {
                if (abs(i - um[nums[i]]) <= k)
                    return true;
            }
            um[nums[i]] = i;
        }
        return false;
    }
};

// 2444. Count Subarrays With Fixed Bounds
class Solution
{
public:
    typedef long long ll;
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();
        ll ans = 0;
        ll minPos = -1;
        ll maxPos = -1;
        ll culpritInd = -1;
        for (int i = 0; i < n; i++)
        {
            if (minK > nums[i] || nums[i] > maxK)
            {
                culpritInd = i;
            }
            if (nums[i] == minK)
            {
                minPos = i;
            }
            if (nums[i] == maxK)
            {
                maxPos = i;
            }
            int smaller = min(minPos, maxPos);
            int temp = smaller - culpritInd;
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};

// 1456. Maximum Number of Vowels in a Substring of Given Length
class Solution
{
public:
    // bool isVowel(char c){
    //     return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ;
    // }
    int maxVowels(string s, int k)
    {
        int n = s.length();
        int right = 0, left = 0;
        int maxV = INT_MIN;
        int count = 0;

        auto isVowel = [&](char c) { /// writting lamda function
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        while (right < n)
        {
            if (isVowel(s[right]))
            {
                count++;
            }
            if (right - left + 1 == k)
            {
                maxV = max(maxV, count);
                if (maxV == k)
                    return maxV;
                if (isVowel(s[left]))
                    count--;
                left++;
            }
            right++;
        }
        return maxV;
    }
};

// 2090. K Radius Subarray Averages
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> result(n, -1);

        if (k == 0)
            return nums; // Edge case: window size = 1
        if (n < 2 * k + 1)
            return result; // Not enough room

        vector<long long> prefix(n, 0); // prefix[i] = sum of nums[0] to nums[i-1]
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = k; i < n - k; i++)
        {
            int leftIdx = i - k;
            int rightIdx = i + k;
            long long sum = prefix[rightIdx];
            if (leftIdx > 0)
            {
                sum -= prefix[leftIdx - 1];
            }
            result[i] = sum / (2 * k + 1);
        }

        return result;
    }
};