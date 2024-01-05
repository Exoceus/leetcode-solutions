class Solution
{
public:
    bool isPalindrome(string s)
    {
        return naive(s);
    }

    // blind
    bool naive(string s)
    {
        int midpoint = 0;

        s = clean(s);

        if (s.length() % 2 == 0)
        {
            midpoint = s.length() / 2;
        }
        else
        {
            midpoint = (s.length() / 2) + 1;
        }

        for (int i = 0; i < midpoint; i++)
        {
            if (s[i] != s[s.length() - 1 - i])
            {
                return false;
            }
        }

        return true;
    }

    // probs can do something with "two pointers" so that we do input cleaning and palindrome checking in one pass

    // HELPERS

    // cleans the string to remove upercase, and remove non-alphanumeric
    string clean(string s)
    {
        string out = "";

        for (int i = 0; i < s.length(); i++)
        {
            // based of ascii
            if ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 97 && s[i] <= 122))
            {
                out += s[i];
            }
            if (s[i] >= 65 && s[i] <= 90)
            {
                out += (s[i] + 32);
            }
        }

        return out;
    }
};