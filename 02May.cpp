// 124. Binary Tree Maximum Path Sum
class Solution
{
public:
    int maxSum;
    int counting(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = max(0, counting(root->left)); // to avoid the negative values
        int right = max(0, counting(root->right));

        maxSum = max(maxSum, left + right + root->val);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root)
    {
        maxSum = root->val; // assuming the root itself is the maximum
        counting(root);
        return maxSum;
    }
};