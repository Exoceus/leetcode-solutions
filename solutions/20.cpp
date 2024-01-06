class Solution
{
public:
    bool isValid(string s)
    {
        return naiveStack(s);
    }

    // blind
    bool naiveStack(string s)
    {
        vector<char> stack;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stack.push_back(s[i]);
            }
            else
            {
                if (stack.empty())
                {
                    return false;
                }

                if (s[i] == ')' && stack.back() == '(')
                {
                    stack.pop_back();
                }

                else if (s[i] == ']' && stack.back() == '[')
                {
                    stack.pop_back();
                }

                else if (s[i] == '}' && stack.back() == '{')
                {
                    stack.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }

        if (stack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};