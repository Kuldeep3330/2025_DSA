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

void reverseStr(string &str, int left, int right)
{
    while (left < right)
    {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

int main()
{
    string str = "I love you";
    int n = str.length();

    // Step 1: Reverse each word
    int left = 0;
    for (int right = 0; right <= n; right++)
    {
        if (right == n || str[right] == ' ')
        {
            reverseStr(str, left, right - 1);
            left = right + 1;
        }
    }

    // Step 2: Reverse the entire string
    reverseStr(str, 0, n - 1);

    cout << str << endl; // Output: "you love I"

    // // leftmost non-repeating element
    // string str = "Kuldeep";
    // vector<int> count(26, 0);
    // for (int i = 0; i < str.length(); i++)
    // {
    //     count[str[i] - 'a']++;
    // }
    // for (int i = 0; i < 26; i++)
    // {
    //     if (count[i] == 1)
    //     {
    //         cout << (char)(i + 'a') << " not repeates\n";
    //         break;
    //     }
    // }
    // cout << "program executes successfully\n";
    // leftmost repeating character
    // string str = "Kuldeep";
    // vector<int> count(26, 0);
    // for (int i = 0; i < str.length(); i++)
    // {
    //     count[str[i] - 'a']++;
    // }
    // for (int i = 0; i < 26; i++)
    // {
    //     if (count[i] > 1)
    //     {
    //         cout << (char)(i + 'a') << " repeates\n";
    //     }
    // }
    // cout << "program executes successfully\n";

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