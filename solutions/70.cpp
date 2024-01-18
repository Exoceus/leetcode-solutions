class Solution
{
public:
    int climbStairs(int n)
    {
        return simpleRecurse(n);
    }

    // blind
    int simpleRecurse(int n)
    {
        map<int, int> lookup; // for memoization
        lookup[1] = 1;
        lookup[2] = 2;
        return climbHelper(n, lookup);
    }

    int climbHelper(int n, map<int, int> &lookup)
    {
        if (lookup.count(n))
        {
            return lookup[n];
        }
        else
        {
            int subtotal = climbHelper(n - 1, lookup) + climbHelper(n - 2, lookup);
            lookup[n] = subtotal;
            return subtotal;
        }
    }
};