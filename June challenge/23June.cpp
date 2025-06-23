// 2081. Sum of k-Mirror Numbers
class Solution
{
public:
    long long createPalindrome(long long num, bool odd)
    {
        long long x = num;
        if (odd)
            x /= 10;
        while (x > 0)
        {
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }

    bool isPalindrome(long long num, int base)
    {
        vector<int> digits;
        while (num > 0)
        {
            digits.push_back(num % base);
            num /= base;
        }
        int i = 0, j = digits.size() - 1;
        while (i < j)
        {
            if (digits[i++] != digits[j--])
                return false;
        }
        return true;
    }

    long long kMirror(int k, int n)
    {
        long long sum = 0;
        for (long long len = 1; n > 0; len *= 10)
        {
            for (long long i = len; n > 0 && i < len * 10; i++)
            {
                long long p = createPalindrome(i, true);
                if (isPalindrome(p, k))
                {
                    sum += p;
                    n--;
                }
            }
            for (long long i = len; n > 0 && i < len * 10; i++)
            {
                long long p = createPalindrome(i, false);
                if (isPalindrome(p, k))
                {
                    sum += p;
                    n--;
                }
            }
        }
        return sum;
    }
};

// Minimum sum

class Solution
{
public:
    string sm(string &a, string &b)
    {
        string temp = "";
        int n = a.size();
        int m = b.size();
        int cary = 0;
        int i = n - 1, j = m - 1;
        while (i >= 0 and j >= 0)
        {
            int sm = a[i] - '0' + b[j] - '0' + cary;
            temp += sm % 10 + '0';
            cary = sm / 10;
            i--, j--;
        }
        while (i >= 0)
        {
            int sm = a[i] - '0' + cary;
            temp += sm % 10 + '0';
            cary = sm / 10;
            i--;
        }
        while (j >= 0)
        {
            int sm = b[j] - '0' + cary;
            temp += sm % 10 + '0';
            cary = sm / 10;
            j--;
        }
        if (cary)
        {
            temp += cary + '0';
        }
        while (temp.back() == '0')
            temp.pop_back();
        reverse(begin(temp), end(temp));
        return temp;
    }
    string minSum(vector<int> &arr)
    {
        // code here
        sort(begin(arr), end(arr));
        string a = "", b = "";
        int n = arr.size();
        for (int i = 0; i < n; i += 2)
        {
            a += arr[i] + '0';
        }
        for (int i = 1; i < n; i += 2)
        {
            b += arr[i] + '0';
        }
        return sm(a, b);
    }
};