// Alien Dictionary

string findOrder(vector<string> &words)
{
    int n = words.size();
    map<char, vector<char>> adj;
    vector<bool> freq1(26, 0), freq2(26, 0);
    vector<int> inDegree(26, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int sz1 = words[i].length();
        int sz2 = words[i + 1].length();
        for (int j = 0; j < sz1; j++)
        {
            if (j >= sz2)
                return "";
            if (words[i][j] != words[i + 1][j])
            {
                adj[words[i][j]].push_back(words[i + 1][j]);
                freq1[words[i][j] - 'a'] = 1;
                freq1[words[i + 1][j] - 'a'] = 1;
                inDegree[words[i + 1][j] - 'a']++;
                break;
            }
        }
    }
    string ans = "";
    queue<char> q;
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i])
        {
            cnt++;
            if (inDegree[i] == 0)
                q.push(i + 'a');
        }
    }
    while (!q.empty())
    {
        char u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto &v : adj[u])
        {
            inDegree[v - 'a']--;
            if (inDegree[v - 'a'] == 0)
            {
                q.push(v);
            }
        }
    }
    if (ans.length() != cnt)
        return "";
    for (auto &ele : words)
    {
        for (auto &c : ele)
            freq2[c - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] == 0 and freq2[i] == 1)
            ans.push_back(i + 'a');
    }
    return ans;
}

// 54. Spiral Matrix

vector<int> spiralOrder(vector<vector<int>> &mat)
{
    int r = mat.size();
    int c = mat[0].size();
    vector<int> result;
    int top = 0, left = 0, bottom = r - 1, right = c - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            // cout << mat[top][i] << " ";
            result.push_back(mat[top][i]);
        top++;
        for (int i = top; i <= bottom; i++)
            // cout << mat[i][right] << " ";
            result.push_back(mat[i][right]);
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                // cout << mat[bottom][i] << " ";
                result.push_back(mat[bottom][i]);
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                // cout << mat[i][left] << " ";
                result.push_back(mat[i][left]);
            left++;
        }
    }
    return result;
}