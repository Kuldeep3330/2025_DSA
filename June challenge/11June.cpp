// Remove the balls

class Solution
{
public:
    int findLength(vector<int> &color, vector<int> &radius)
    {
        int n = color.size();
        vector<int> st;

        for (int i = 0; i < n; i++)
        {
            if (!st.empty() &&
                color[i] == color[st.back()] &&
                radius[i] == radius[st.back()])
            {
                st.pop_back();
            }
            else
            {
                st.push_back(i);
            }
        }

        return st.size();
    }
};