#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &v, int sum, int i)
{
    if (sum == 0)
    {
        return true;
    }
    if (i == v.size())
    {
        return false;
    }

    if (v[i] <= sum)
    {
        return helper(v, sum - v[i], i + 1);
    }
    return helper(v, sum, i + 1);
}
int main()
{
    vector<int> v = {2, 7, 4, 5, 19};
    int sum = 12;
    return helper(v, sum, 0);
    return 0;
}