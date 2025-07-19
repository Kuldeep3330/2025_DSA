#include <bits/stdc++.h>
using namespace std;

// balanced parenthesis
bool matching(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}
bool isBalanced(string &str)
{
    stack<char> s;
    for (char x : str)
    {
        if (x == '(' || x == '{' || x == '[')
        {
            s.push(x);
        }
        else
        {
            if (s.empty() || !matching(s.top(), x))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return (s.empty() == true);
}

int main()
{

    string str = "((())";
    cout << isBalanced(str);

    return 0;
}