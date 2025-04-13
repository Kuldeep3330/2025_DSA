
// 42. Trapping Rain Water
int trap(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lMax(n);
    lMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        lMax[i] = max(lMax[i - 1], arr[i]);
    }

    vector<int> rMax(n);
    rMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rMax[i] = max(rMax[i + 1], arr[i]);
    }

    int totalWater = 0;
    for (int i = 1; i < n - 1; i++)
    {
        totalWater += min(lMax[i], rMax[i]) - arr[i];
    }
    return totalWater;
}