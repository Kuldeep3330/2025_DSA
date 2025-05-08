// 981. Time Based Key-Value Store
unordered_map<string, vector<pair<int, string>>> mp;

void set(string key, string value, int timestamp)
{
    mp[key].push_back({timestamp, value});
}

string get(string key, int timestamp)
{
    if (mp.find(key) == mp.end())
        return "";

    auto &vec = mp[key];
    int low = 0, high = vec.size() - 1;
    string result = "";

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (vec[mid].first <= timestamp)
        {
            result = vec[mid].second;
            low = mid + 1; // keep searching for later but valid timestamp
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
}