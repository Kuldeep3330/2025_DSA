// 948. Bag of Tokens
class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int score = 0, maxScore = 0;
        int i = 0, j = tokens.size() - 1;

        while (i <= j)
        {
            if (power >= tokens[i])
            {
                power -= tokens[i++];
                score++;
                maxScore = max(maxScore, score);
            }
            else if (score >= 1)
            {
                power += tokens[j--];
                score--;
            }
            else
            {
                break;
            }
        }

        return maxScore;
    }
};
