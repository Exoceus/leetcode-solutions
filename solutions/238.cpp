class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        return twoPass(nums);
    }

    // inspired
    vector<int> prefixSuffixArrs(vector<int> &nums)
    {
        int prefix[nums.size()];
        int suffix[nums.size()];

        // could be cleaner
        int curr_prefix = nums[0]; // we know nums length >= 2
        prefix[0] = curr_prefix;
        for (int i = 1; i < nums.size(); i++)
        {
            curr_prefix *= nums[i];
            prefix[i] = curr_prefix;
        }

        int curr_suffix = nums[nums.size() - 1];
        suffix[nums.size() - 1] = curr_suffix;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            curr_suffix *= nums[i];
            suffix[i] = curr_suffix;
        }

        vector<int> final;

        final.push_back(suffix[1]);
        for (int i = 1; i < nums.size() - 1; i++)
        {
            final.push_back(prefix[i - 1] * suffix[i + 1]);
        }
        final.push_back(prefix[nums.size() - 2]);
        return final;
    }

    // blind (improvement of inspired soln)
    vector<int> twoPass(vector<int> &nums)
    {
        // write suffix_arr in same spot
        vector<int> final;

        int prev_prefix = nums[0]; // we know nums length >= 2
        final.push_back(1);
        for (int i = 1; i < nums.size(); i++)
        {
            final.push_back(prev_prefix);
            prev_prefix *= nums[i];
        }

        int prev_suffix = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            final[i] *= prev_suffix;
            prev_suffix *= nums[i];
        }
        return final;
    }
};