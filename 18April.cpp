// sliding Window starts
// Count Occurences of Anagrams
int search(string &pat, string &txt)
{
    // code here
    int k = pat.length();
    int n = txt.length();

    vector<int> freqP(26, 0), freqT(26, 0);

    for (char c : pat)
        freqP[c - 'a']++; // storing the frequency of pattern

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        freqT[txt[i] - 'a']++;

        if (i >= k)
        { // agar k se jyada ho remove the out of window elements i-k
            freqT[txt[i - k] - 'a']--;
        }

        if (i >= k - 1 && freqP == freqT)
        {
            count++;
        }
    }
    return count;
}

// 1658. Minimum Operations to Reduce X to Zero

int minOperations(vector<int> &nums, int x)
{
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    int target = total - x;

    if (target < 0)
        return -1;

    int maxLen = INT_MIN;
    int left = 0, currSum = 0;

    for (int right = 0; right < n; right++)
    {
        currSum += nums[right];

        while (currSum > target && left <= right)
        {
            currSum -= nums[left];
            left++;
        }

        if (currSum == target)
        {
            maxLen = max(maxLen, right - left + 1);
        }
    }
    return maxLen == INT_MIN ? -1 : n - maxLen;
}

// 438. Find All Anagrams in a String

vector<int> findAnagrams(string s, string p)
{
    vector<int> result;

    int k = p.length();
    int n = s.length();
    // frequency arrays to keep track
    vector<int> freqP(26, 0);
    vector<int> freqS(26, 0);

    for (char c : p)
        freqP[c - 'a']++; ////to store frequencies for pat

    for (int i = 0; i < n; i++)
    {
        // to store frequencies for text
        freqS[s[i] - 'a']++;

        // also remove the freq for those who goes out of the bound
        if (i >= k)
        {
            freqS[s[i - k] - 'a']--;
        }

        if (i >= k - 1 && freqP == freqS)
        {
            result.push_back(i - k + 1);
        }
    }

    return result;
}