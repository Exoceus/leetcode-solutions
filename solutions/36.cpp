class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        return bruteForce(board);
    }

    // blind
    bool bruteForce(vector<vector<char>> &board)
    {
        // could use 9 element arr instead of map to save space

        // check for row cond
        for (int i = 0; i < board.size(); i++)
        {
            map<char, bool> nums_present;
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                if (nums_present.count(board[i][j]) || board[i][j] > '9' || board[i][j] < '1')
                {
                    return false;
                }
                nums_present[board[i][j]] = true;
            }
        }

        // check for column cond
        for (int i = 0; i < board[0].size(); i++)
        {
            map<char, bool> nums_present;
            for (int j = 0; j < board.size(); j++)
            {
                if (board[j][i] == '.')
                {
                    continue;
                }
                if (nums_present.count(board[j][i]) || board[j][i] > '9' || board[j][i] < '1')
                {
                    return false;
                }
                nums_present[board[j][i]] = true;
            }
        }

        // check for 3x3 condition
        for (int i = 0; i < board.size(); i += 3)
        {
            for (char j = 0; j < board[0].size(); j += 3)
            {
                map<int, bool> nums_present;
                for (int a = i; a < i + 3; a++)
                {
                    for (int b = j; b < j + 3; b++)
                    {
                        if (board[a][b] == '.')
                        {
                            continue;
                        }
                        if (nums_present.count(board[a][b]) || board[a][b] > '9' || board[a][b] < '1')
                        {
                            return false;
                        }
                        nums_present[board[a][b]] = true;
                    }
                }
            }
        }

        return true;
    }
};