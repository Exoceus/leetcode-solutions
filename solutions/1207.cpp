class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        return twoHashMaps(arr);
    }

    // blind
    bool twoHashMaps(vector<int> &arr)
    {
        map<int, int> occurences;

        for (int i = 0; i < arr.size(); ++i)
        {
            if (occurences.count(arr[i]))
            {
                occurences[arr[i]]++;
            }
            else
            {
                occurences[arr[i]] = 1;
            }
        }

        map<int, bool> unique;

        for (auto &item : occurences)
        {
            if (unique.count(item.second))
            {
                return false;
            }
            else
            {
                unique[item.second] = true;
            }
        }
        return true;
    }
};