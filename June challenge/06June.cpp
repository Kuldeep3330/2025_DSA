// 2434. Using a Robot to Print the Lexicographically Smallest String
class Solution
{
public:
    // Helper function to find the lexicographically smallest remaining character
    char l(vector<int> &freq)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i])
                return 'a' + i;
        }
        return 'a';
    }

    string robotWithString(string s)
    {
        stack<char> st;
        string t = "";
        vector<int> freq(26);

        // Count frequency of each character in s
        for (char ch : s)
        {
            freq[ch - 'a']++;
        }

        // Iterate over characters in s
        for (char ch : s)
        {
            st.push(ch);
            freq[ch - 'a']--;

            // Pop from stack to result if stack top ≤ smallest remaining char
            while (!st.empty() && st.top() <= l(freq))
            {
                t += st.top();
                st.pop();
            }
        }

        // Pop remaining characters
        while (!st.empty())
        {
            t += st.top();
            st.pop();
        }

        return t;
    }
};

// Search Pattern (Rabin-Karp Algorithm)

class Solution
{
public:
    vector<int> search(string &pat, string &txt)
    {
        int n = txt.length();
        int m = pat.length();

        vector<int> ans;
        vector<int> freqPt(26, 0);
        vector<int> freqTxt(26, 0);

        for (int i = 0; i < m; i++)
        {
            freqPt[pat[i] - 'a']++;
            freqTxt[txt[i] - 'a']++;
        }

        for (int i = 0; i <= n - m; i++)
        {
            if (freqPt == freqTxt)
            {
                bool match = true;
                for (int j = 0; j < m; j++)
                {
                    if (pat[j] != txt[i + j])
                    {
                        match = false;
                        break;
                    }
                }

                if (match)
                    ans.push_back(i + 1);
            }

            if (i + m < n)
            {
                freqTxt[txt[i] - 'a']--;
                freqTxt[txt[i + m] - 'a']++;
            }
        }

        return ans;
    }
};