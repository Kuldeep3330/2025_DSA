int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end());
    int n = citations.size();
    int maxim = 0;
    for (int i = 0; i < n; i++)
    {
        if (citations[i] >= n - i)
        {
            maxim = max(maxim, n - i);
        }
    }
    return maxim;
}