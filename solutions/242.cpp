class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        return freqMap(s, t);
    }

    // blind
    // O(n)
    bool freqMap(string s, string t)
    {
        map<char, int> freq_map_s;
        map<char, int> freq_map_t;

        for (int i = 0; i < s.size(); i++)
        {
            if (freq_map_s.count(s[i]))
            {
                freq_map_s[s[i]]++;
            }
            else
            {
                freq_map_s[s[i]] = 1;
            }
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (freq_map_t.count(t[i]))
            {
                freq_map_t[t[i]]++;
            }
            else
            {
                freq_map_t[t[i]] = 1;
            }
        }

        if (freq_map_t.size() != freq_map_s.size())
        {
            return false;
        }

        for (auto &element : freq_map_s)
        {
            if (!freq_map_t.count(element.first) || freq_map_t[element.first] != element.second)
            {
                return false;
            }
        }

        return true;
    }

    // blind
    // O(n * log(n))
    bool sorting(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s.size() != t.size())
        {
            return false;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != t[i])
            {
                return false;
            }
        }

        return true;
    }
};