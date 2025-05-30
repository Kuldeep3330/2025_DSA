// 2187. Minimum Time to Complete Trips

class Solution
{
public:
    typedef long long ll;
    ll minimumTime(vector<int> &time, int totalTrips)
    {
        ll l = 1;
        ll r = (ll)*min_element(time.begin(), time.end()) * totalTrips;

        while (l < r)
        {
            ll mid = l + (r - l) / 2;
            ll trips = 0;
            for (int t : time)
            {
                trips += mid / t;
            }
            if (trips >= totalTrips)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};
