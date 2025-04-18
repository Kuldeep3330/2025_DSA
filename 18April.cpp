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