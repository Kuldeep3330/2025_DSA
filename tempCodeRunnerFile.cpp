#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};
int main()
{
    Point arr[] = {{7, 8}, {3, 4}, {5, 6}};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, [](Point a, Point b)
         { return a.x < b.x; });
    for (auto p : arr)
    {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}