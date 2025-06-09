// 52. N-Queens II
class Solution
{
public:
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void nQueen(vector<string> &board, int row, int n, int &result)
    {
        if (row == n)
        {
            result++;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (isSafe(board, row, j, n))
            {
                board[row][j] = 'Q';
                nQueen(board, row + 1, n, result);
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        int result = 0;
        nQueen(board, 0, n, result);
        return result;
    }
};

// 440. K-th Smallest in Lexicographical Order
class Solution
{
private:
    int check(long a, long b, long n)
    {
        int gap = 0;
        while (a <= n)
        {
            gap += min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    }

public:
    int findKthNumber(long n, int k)
    {
        long num = 1;
        for (int i = 1; i < k;)
        {
            int req = check(num, num + 1, n);
            if (i + req <= k)
            {
                i += req;
                num++;
            }
            else
            {
                i++;
                num *= 10;
            }
        }
        return num;
    }
};
// BST with Dead End
class Solution
{
public:
    vector<int> arr, leaf;

    void inorder(Node *node)
    {
        if (!node)
            return;

        inorder(node->left);
        arr.push_back(node->data);
        if (!node->left && !node->right)
            leaf.push_back(node->data);
        inorder(node->right);
    }

    bool isDeadEnd(Node *root)
    {
        arr = {0};
        leaf = {};
        inorder(root);

        int j = 0;
        for (int i = 1; i < arr.size() && j < leaf.size(); ++i)
        {
            if (arr[i] == leaf[j])
            {
                if (arr[i - 1] == leaf[j] - 1 && arr[i + 1] == leaf[j] + 1)
                    return true;
                ++j;
            }
        }

        return false;
    }
};