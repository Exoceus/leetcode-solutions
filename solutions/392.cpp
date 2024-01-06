class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        return optimizedRecursion(s, t);
    }

    // blind
    bool naiveRecursion(string s, string t)
    {
        // this function was pretty slow
        // im suspecting this is because we are constantly reassing the string
        if (s.length() == 0)
        {
            return true;
        }

        while (s[0] != t[0] && t.length() > 0)
        {
            t = t.substr(1);
        }

        if (t.length() == 0)
        {
            return false;
        }

        return naiveRecursion(s.substr(1), t.substr(1));
    }

    // blind
    bool optimizedRecursion(string s, string t, int i = 0, int j = 0)
    {
        // instead of modifying strings, just use "pointers" to current characters being compared
        if (i >= s.length())
        {
            return true;
        }

        while (s[i] != t[j] && j < t.length())
        {
            j++;
        }

        if (j >= t.length())
        {
            return false;
        }

        return optimizedRecursion(s, t, ++i, ++j);
    }
};