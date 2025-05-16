// 1493. Longest Subarray of 1's After Deleting One Element
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int zeroCount = 0;
        int maxLen = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            if (nums[j] == 0)
                zeroCount++;
            while (zeroCount > 1)
            {
                if (nums[i] == 0)
                    zeroCount--;
                i++;
            }
            maxLen = max(maxLen, j - i);
            j++;
        }
        return maxLen;
    }
};

// 2024. Maximize the Confusion of an Exam
// Brute force
class Solution
{
public:
    int result = 0;
    int n;
    void findMax(string &answerKey)
    {
        int length = 0;
        int i = 0;
        while (i < n)
        {
            if (answerKey[i] == 'T')
            {
                length = 1;
                i++;
                while (i < n && answerKey[i] == 'T')
                {
                    length++;
                    i++;
                }
                result = max(result, length);
            }
            else
            {
                length = 1;
                i++;
                while (i < n && answerKey[i] == 'F')
                {
                    length++;
                    i++;
                }
                result = max(result, length);
            }
        }
    }
    void solve(int idx, string &answerKey, int k)
    {
        findMax(answerKey);
        if (idx >= n || k <= 0)
        {
            return;
        }
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T';
        solve(idx + 1, answerKey, k - 1);
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T';
        solve(idx + 1, answerKey, k);
    }
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        n = answerKey.length();
        solve(0, answerKey, k);
        return result;
    }
};

// 2024. Maximize the Confusion of an Exam(sliding window)
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int n = answerKey.length();
        int result = INT_MIN;
        int j = 0, i = 0;
        int falseCount = 0;
        while (j < n)
        {
            if (answerKey[j] == 'F')
            {
                falseCount++;
            }
            while (falseCount > k)
            {
                if (answerKey[i] == 'F')
                {
                    falseCount--;
                }
                i++;
            }

            result = max(result, j - i + 1);
            j++;
        }
        i = 0, j = 0, falseCount = 0;
        while (j < n)
        {
            if (answerKey[j] == 'T')
            {
                falseCount++;
            }
            while (falseCount > k)
            {
                if (answerKey[i] == 'T')
                {
                    falseCount--;
                }
                i++;
            }

            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};
// optimized code
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int n = answerKey.length();
        int result = INT_MIN;
        int j = 0, i = 0;
        unordered_map<int, int> um;

        while (j < n)
        {
            um[answerKey[j]]++;
            while (min(um['T'], um['F']) > k)
            {
                um[answerKey[i]]--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};