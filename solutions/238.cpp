class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        return prefixSuffixArrs(nums);
    }

    // inspired
    vector<int> prefixSuffixArrs(vector<int> &nums)
    {
        int prefix[nums.size()];
        int suffix[nums.size()];

        // this could could be cleaner
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
};