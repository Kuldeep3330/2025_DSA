// 2131. Longest Palindrome by Concatenating Two Letter Words
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> m;
        int n = words.size();
        bool flag = true;
        int count = 0;
        for (string s : words)
        {
            m[s]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (m[words[i]])
            {
                if (words[i][1] == words[i][0])
                {
                    count += (m[words[i]] / 2) * 4;
                    if (m[words[i]] % 2 == 1)
                        flag = false;
                }
                else
                {
                    string temp = "";
                    temp += words[i][1];
                    temp += words[i][0];
                    count += min(m[words[i]], m[temp]) * 4;
                    m[temp] = 0;
                }
                m[words[i]] = 0;
            }
        }
        if (!flag)
            count += 2;
        return count;
    }
};

// Pythagorean Triplet

// User function template for C++
class Solution
{
public:
    // Function to check if the
    // Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n)
    {
        // code here

        int max = INT_MIN;

        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            m[arr[i] * arr[i]] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int idx = arr[i] * arr[i];

                int idy = arr[j] * arr[j];

                if (m[idx + idy])
                    return true;
            }
        }

        return false;
    }
};