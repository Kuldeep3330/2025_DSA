
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

// Find Only Repetitive Element from 1 to n-1
int findDuplicate(vector<int> &arr)
{
    // code here
    // rabbit and tortoise
    int first = 0, second = 0;
    do
    {
        first = arr[first];
        second = arr[arr[second]];
    } while (first != second);
    second = 0;

    while (first != second)
    {
        first = arr[first];
        second = arr[second];
    }
    return first;
}

// 20. Valid Parentheses
bool isChecked(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}
bool isValid(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if (s.empty() != true && isChecked(s.top(), str[i]))
        {
            s.pop();
        }
        else
        {
            return false;
        }
    }
    return (s.empty() == true);
}