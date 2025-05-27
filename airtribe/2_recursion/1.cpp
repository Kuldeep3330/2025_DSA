// https://leetcode.com/problems/house-robber/description/ (TRY)
// https://leetcode.com/problems/climbing-stairs/ [Easy]
// https://leetcode.com/problems/fibonacci-number/ (TRY)
// Print N to 1
// Print 1 to N (Must Try)
// https://leetcode.com/problems/longest-common-subsequence/description/ (Really Good)
// https://leetcode.com/problems/powx-n/description/
class Solution
{
public:
    double solve(double x, long long n)
    {
        if (n == 0)
            return 1.0;

        if (n < 0)
            return solve(1 / x, -n);
        if (n % 2 == 0)
            return solve(x * x, n / 2);
        return x * solve(x * x, (n - 1) / 2); // n is odd
    }
    double myPow(double x, int n)
    {
        long long N = n;
        return solve(x, N);
    }

    // https://leetcode.com/problems/generate-parentheses/description/
    // https://www.geeksforgeeks.org/check-if-a-number-is-palindrome/ [Easy]
    // https://www.geeksforgeeks.org/program-for-length-of-a-string-using-recursion/ [Easy]
    // Factorial -> N! => N * N - 1 * N - 2 * N - 3 . … 1 => 4! => 4*3*2*1=> 24 [Easy]
