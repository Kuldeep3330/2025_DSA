#include <bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> &v, int sum, int i, vector<int> &ans)
{
    if (sum == 0)
    {
        for (int x : ans)
            cout << x << " ";
        cout << endl;
        return 1;
    }

    if (i == v.size())
        return 0;

    int pick = 0;
    if (sum >= v[i])
    {
        ans.push_back(v[i]);
        pick = subsetSum(v, sum - v[i], i, ans);
        ans.pop_back();
    }
    int notPick = subsetSum(v, sum, i + 1, ans);

    return pick + notPick;
}

int main()
{
    vector<int> v = {2, 7, 4, 5, 19};
    int sum = 12;
    vector<int> ans;

    cout << "Total subsets with sum " << sum << ": " << subsetSum(v, sum, 0, ans) << endl;

    return 0;
}
