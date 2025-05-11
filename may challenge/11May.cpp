// 26. Remove Duplicates from Sorted Array
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int first = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[first] != nums[i])
            {
                first++;
                nums[first] = nums[i];
            }
        }
        //    nums.resize(first+1);
        return first + 1;
    }
};

// 151. Reverse Words in a String
class Solution
{
public:
    void reverseStr(string &str, int low, int high)
    {
        while (low < high)
        {
            swap(str[low++], str[high--]);
        }
    }

    // Helper to trim extra spaces
    string trimSpaces(const string &s)
    {
        // string s = "   the   sky is   blue  ";
        string result;
        int i = 0, n = s.size();

        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++; // skip leading spaces
            if (i >= n)
                break; // agar ise add nhi kiya to last me bhi ' ' ek space add ho jayega
            if (!result.empty())
                result += ' ';
            while (i < n && s[i] != ' ')
                result += s[i++];
        }

        return result;
    }

    string reverseWords(string s)
    {
        s = trimSpaces(s);
        int n = s.length();

        // Step 2: Reverse each word
        int start = 0;
        for (int end = 0; end <= n; end++)
        {
            if (end == n || s[end] == ' ')
            {
                reverseStr(s, start, end - 1);
                start = end + 1;
            }
        }
        // Step 1: Reverse the entire string
        reverseStr(s, 0, n - 1);

        return s;
    }
};