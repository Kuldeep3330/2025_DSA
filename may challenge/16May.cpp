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