
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