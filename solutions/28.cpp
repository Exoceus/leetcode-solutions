class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return naive(haystack, needle);
    }

    // blind
    int naive(string haystack, string needle)
    {
        if (needle.length() > haystack.length())
        {
            return -1;
        }

        for (int i = 0; i < haystack.length() - needle.length() + 1; i++)
        {
            int j = 0;
            int temp_i = i;

            while (haystack[temp_i] == needle[j])
            {
                j++;
                temp_i++;

                if (j == needle.length())
                {
                    return i;
                }
            }
        }
        return -1;
    }

    // there is boyer moore with optimizations to skip past certain indices with last occurence dict
};
