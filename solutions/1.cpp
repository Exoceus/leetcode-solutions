class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        return dict(nums, target);
    }

    // blind
    vector<int> dict(vector<int> &nums, int target)
    {
        // store numbers in a dict for quick retrieval
        map<int, vector<int>> numbers;

        for (int i = 0; i < nums.size(); i++)
        {
            if (numbers.count(nums[i]) == 0)
            {
                numbers[nums[i]] = vector<int>{i};
            }
            else
            {
                numbers[nums[i]].push_back(i);
            }
        }

        for (auto &number : numbers)
        {
            if (numbers.count(target - number.first))
            {
                if (number.first * 2 == target)
                {
                    return vector<int>{number.second[0], number.second[1]};
                }

                return vector<int>{number.second[0], numbers[target - number.first][0]};
            }
        }

        return vector<int>{0, 1};
    }
};