// 974. Subarray Sums Divisible by K
class Solution
{
public:
    int subarraysDivByK(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> um;
        int sum = 0;

        um[0] = 1;
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            int rem = sum % k;
            if (rem < 0)
            {
                rem += k;
            }
            if (um.find(rem) != um.end())
            {
                result += um[rem];
            }
            um[rem]++;
        }
        return result;
    }
};

// 345. Reverse Vowels of a String
class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
    string reverseVowels(string s)
    {
        int n = s.length();
        int low = 0;
        int high = n - 1;
        while (low < high)
        {

            while (low < high && !isVowel(s[low]))
            {
                low++;
            }
            while (low < high && !isVowel(s[high]))
            {
                high--;
            }
            swap(s[low], s[high]);
            low++;
            high--;
        }
        return s;
    }
};