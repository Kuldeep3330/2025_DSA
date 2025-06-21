// 1328. Break a Palindrome
class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.length();
        if (n == 1)
            return "";
        for (int i = 0; i < n / 2; i++)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};
// 991. Broken Calculator
class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        if (startValue >= target)
        {
            return startValue - target;
        }
        if (target % 2 == 0)
        {
            return 1 + brokenCalc(startValue, target / 2);
        }
        else
        {
            return 1 + brokenCalc(startValue, target + 1);
        }
    }
};