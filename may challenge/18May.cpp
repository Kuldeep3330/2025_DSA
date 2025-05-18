// 1838. Frequency of the Most Frequent Element
class Solution
{
public:
    int bSearch(vector<int> &nums, vector<long> &prefixSum, int targetIdx, int k)
    {
        int low = 0, high = targetIdx;
        int result = targetIdx;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int count = targetIdx - mid + 1;

            long windowSum = 1L * count * nums[targetIdx];
            long originalSum = prefixSum[targetIdx] - (mid > 0 ? prefixSum[mid - 1] : 0);

            int ops = windowSum - originalSum;

            if (ops > k)
            {
                low = mid + 1;
            }
            else
            {
                result = mid;
                high = mid - 1;
            }
        }

        return targetIdx - result + 1;
    }

    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            int freq = bSearch(nums, prefixSum, i, k);
            result = max(result, freq);
        }

        return result;
    }
};

// Level Order in spiral form(GFG)

class Solution
{
public:
    vector<int> findSpiral(Node *root)
    {
        if (!root)
        {
            return {};
        }

        // Make a Queue
        queue<Node *> q;
        vector<int> result;

        q.push(root);

        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> currentLevel;

            // Level Traversal
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                currentLevel.push_back(node->data);

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            // if level is even reverse the order
            if (level % 2 == 0)
            {
                reverse(currentLevel.begin(), currentLevel.end());
            }

            result.insert(result.end(), currentLevel.begin(), currentLevel.end());
            level++;
        }
        return result;
    }
};