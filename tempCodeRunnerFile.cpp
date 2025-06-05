#include <bits/stdc++.h>
using namespace std;
void print_n(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    print_n(n - 1);
    cout << n << " ";
    print_n(n - 1);
}
int main()
{
    print_n(3);

    return 0;
}