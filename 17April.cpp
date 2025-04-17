#include <bits/stdc++.h>
using namespace std;

// bool isSubsRec(string s1, string s2, int n, int m){
//     if(m==0) return true;
//     if(n==0) return false;
//     if(s1[n-1] == s2[m-1]){
//         return isSubsRec(s1, s2, n-1, m-1);
//     }else
//     return isSubsRec(s1, s2, n-1, m);
// }
int main()
{
    // leftmost repeating character
    string str = "Kuldeep";
    vector<int> count(26, 0);
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 1)
        {
            cout << (char)(i + 'a') << " repeates\n";
        }
    }
    cout << "program executes successfully\n";

    // //check Anagram
    // string str1 = "listen";
    // string str2 = "silen";
    // vector<int> count(26, 0);
    // for (int i = 0; i < str1.length(); i++)
    // {
    //     count[str1[i] - 'a']++;
    //     count[str2[i] - 'a']--;
    // }
    // for (int i = 0; i < 26; i++)
    // {
    //     if (count[i] > 0)
    //     {
    //         cout << "not anagram\n";
    //     }
    // }
    // cout << "program executed successfully\n";

    // check if a string is a subsequence of other
    // string str1 = "ABCD";
    // string str2 = "AD";
    // int m = str1.length();
    // int n = str2.length();
    // int i = 0, j = 0;
    // while (i < m && j < n)
    // {
    //     if (str1[i] == str2[j])
    //     {
    //         i++;
    //         j++;
    //     }
    //     i++;
    // }
    // bool flag = (j == n);
    // cout << flag << "\n";
    // return ;

    // palindrome check
    // string str = "ABCDBA";
    // string curr = str;
    // reverse(str.begin(), str.end());

    // bool flag = (str == curr);
    // cout << flag << "\n";

    // int low = 0, high = str.length() - 1;
    // while (low <= high)
    // {
    //     swap(str[low], str[high]);
    //     low++;
    //     high--;
    // }
    // cout << str << "\n";

    // print frequencies of given string
    // string str = "kuldeep";
    // vector<int> count(26, 0);
    // for (int i = 0; i < str.length(); i++)
    // {
    //     count[str[i] - 'a']++;
    // }

    // for (int i = 0; i < 26; i++)
    // {
    //     if (count[i] > 0)
    //     {
    //         cout << (char)(i + 'a') << " " << count[i] << "\n";
    //     }
    // }

    return 0;
}