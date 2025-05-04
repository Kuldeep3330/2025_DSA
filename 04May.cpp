// Smallest distinct window(GFG)
int n = str.length();
int ans = n;

int distinct = 0;
for (char ch : str)
{
    distinct = distinct | (1 << (ch - 'a'));
}
int i = 0;
int j = 0;

vector<int> alph(26, 0);
int present = 0;
while (i < n)
{
    int ch = str[i] - 'a';
    alph[ch]++;
    present = present | (1 << ch);

    while (j <= i && present == distinct)
    {
        ans = min(i - j + 1, ans);
        int temp = str[j] - 'a';
        alph[temp]--;
        if (alph[temp] == 0)
            present = present & (~(1 << temp));
        j++;
    }

    i++;
}
return ans;

// 1128. Number of Equivalent Domino Pairs
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<pair<int, int>, int> mpp;
        int count = 0;
        for (auto &d : dominoes)
        {
            if (d[0] > d[1])
                swap(d[0], d[1]);
            count += mpp[make_pair(d[0], d[1])]++;
        }
        return count;
    }
};