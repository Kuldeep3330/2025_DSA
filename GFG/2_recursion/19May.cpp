// Mean of array

#include <iostream>
#include <algorithm>
using namespace std;
// int mean(int arr[], int n)
// {
//     if (n == 0)
//         return 0;
//     return (arr[n - 1] + mean(arr, n - 1) * (n - 1)) / n;
// }

// decimal to binary number
// int decimalToBinary(int n)
// {
//     int result = 0;
//     while (n > 0)
//     {
//         result = result * 10 + n % 2;
//         n = n / 2;
//     }
//     return result;
// }

// palindrome check
bool isPal(string &str, int left, int right)
{
    if (left >= right)
    {
        return true;
    }
    if (str[left] != str[right])
    {
        return false;
    }
    return isPal(str, left + 1, right - 1);
}
int countSetBits(int n)
{
    int count = 0;
    while (n != 0)
    {
        // count += n & 1;
        // n >>= 1;
        if (n & 1)
        {
            count++;
        }
        // n = n / 2;
        n = n >> 1;
    }
    return count;
}
// using recursion
int setBits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if ((n & 1) == 1)
    {
        return 1 + setBits(n >> 1);
    }
    else
    {
        return setBits(n >> 1);
    }
}
// fibonacci series in reverse order
void reverseFibonacci(int n, int a, int b)
{
    if (n == 0)
    {
        return;
    }
    reverseFibonacci(n - 1, b, a + b);
    cout << a << " ";
}
int main()
{
    reverseFibonacci(10, 0, 1);
    // cout << setBits(7) << endl;
    // cout << countSetBits(16) << endl;
    // string str = "madam";
    // int n = str.length();
    // cout << "Is palindrome: " << isPal(str, 0, n - 1) << endl;
    // cout << "Is palindrome: " << isPal(str) << endl;
    // int ans = decimalToBinary(7);
    // cout << "Decimal to binary: " << ans << endl;
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sum += arr[i];
    // }
    // cout << "Mean of array is: " << (float)sum / n << endl;
    return 0;
}