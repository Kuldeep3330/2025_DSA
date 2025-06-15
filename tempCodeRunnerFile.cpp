#include <bits/stdc++.h>
using namespace std;
bool myCompare(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}
int maxActivities(pair<int, int> arr[], int n)
{
    sort(arr, arr + n, myCompare);
    int prev = 0;
    int res = 1;
    for (int curr = 1; curr < n; curr++)
    {
        if (arr[curr].first >= arr[prev].second)
        {
            res++;
            prev = curr;
        }
    }
    return res;
}

int main()
{
    // print_n(3);

    return 0;
}