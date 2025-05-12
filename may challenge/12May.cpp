#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

void foo(int n, int sum)
{
    int k = 0, j = 0;
    if (n == 0)
    {
        return;
    }
    k = n % 10;
    j = n / 10;
    sum += k;
    foo(j, sum);
    cout << k << endl;
}
int main()
{
    int n = 2048, sum = 0;
    foo(n, sum);
    cout << sum << endl;
    return 0;
}