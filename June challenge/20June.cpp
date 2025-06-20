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

// 881. Boats to Save People
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0, j = n - 1;
        int res = 0;
        while (i <= j)
        {
            if (people[i] + people[j] <= limit)
            {
                i++;
                j--;
                res++;
            }
            else
            {
                j--;
                res++;
            }
        }
        return res;
    }
};
