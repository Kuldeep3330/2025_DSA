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

// 875. Koko Eating Bananas
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            long long hoursNeeded = 0;

            for (int &p : piles)
            {
                hoursNeeded += p / mid;
                if (p % mid > 0)
                {
                    hoursNeeded++;
                }
            }

            if (hoursNeeded <= h)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return high;
    }
};
