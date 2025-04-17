#include <bits/stdc++.h>
using namespace std;

int main()
{
    // print frequencies of given string
    string str = "kuldeep";
    vector<int> count(26, 0);
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            cout << (char)(i + 'a') << " " << count[i] << "\n";
        }
    }

    return 0;
}