class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        return hashmap(nums, k);
    }

    // blind
    bool hashmap(vector<int> &nums, int k)
    {
        // we will be iterating through nums from index 0 onwards
        // thus, we only need to keep the most recently seen index
        // since that will minimize abs(i-j)
        map<int, int> most_recent_seen;

        for (int i = 0; i < nums.size(); i++)
        {
            int current_num = nums[i];

            if (most_recent_seen.count(current_num))
            {
                if (i - most_recent_seen[current_num] <= k)
                {
                    return true;
                }
            }
            most_recent_seen[current_num] = i;
        }

        return false;
    }
};