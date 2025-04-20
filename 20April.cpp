
// 345. Reverse Vowels of a String
bool isVowel(char c)
{
    return c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
}
string reverseVowels(string s)
{
    int low = 0;
    int high = s.length() - 1;
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
        if (low < high)
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }
    return s;
}

// 26. Remove Duplicates from Sorted Array
int removeDuplicates(vector<int> &nums)
{
    int j = 0;
    int n = nums.size();
    int first = nums[0];
    nums[j] = first;
    for (int i = 1; i < n; i++)
    {
        if (first != nums[i])
        {
            first = nums[i];
            nums[++j] = first;
        }
    }

    nums.resize(j + 1);
    return nums.size();
}