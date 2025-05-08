// 3169. Count Days Without Meetings
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        int count = 0;
        int end = 0;
        for (auto &meeting : meetings)
        {
            if (meeting[0] > end)
            {
                count += meeting[0] - end - 1;
            }
            end = max(end, meeting[1]);
        }
        if (end < days)
        {
            count += days - end;
        }
        return count;
    }
};