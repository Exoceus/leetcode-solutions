class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        return naive(nums);
    }

    // blind
    vector<string> naive(vector<int> &nums)
    {
        vector<string> out;

        if (nums.size() == 0)
        {
            return vector<string>{};
        }

        bool inRange = false;
        int a;
        int b;
        int prev;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!inRange)
            {
                a = nums[i];
                inRange = true;
            }
            else
            {
                if (nums[i] != prev + 1)
                {
                    b = prev;

                    if (a == b)
                    {
                        out.push_back(to_string(a));
                    }
                    else
                    {
                        out.push_back(to_string(a) + "->" + to_string(b));
                    }

                    a = nums[i];
                }
            }
            prev = nums[i];
        }

        if (a == nums[nums.size() - 1])
        {
            out.push_back(to_string(a));
        }
        else
        {
            if (a == prev)
            {
                out.push_back(to_string(a));
            }
            else
            {
                out.push_back(to_string(a) + "->" + to_string(prev));
            }
        }

        return out;
    }
};