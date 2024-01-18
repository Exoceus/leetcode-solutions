class Solution
{
public:
    int climbStairs(int n)
    {
        // the idea for both solution is to work backwards
        // for n  = 5, if you reach step 5, you must have come from step 4 (single step) or step 3 (double step)
        // to have reaches step 4, you must have come from step 2 or 3 and so on
        // thus climbStairs(n) = climbStairs(n - 1) + climbStairs(n - 2);
        // this problem emerges to basically just be fibonacci sequence
        return usingDPArray(n);
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

    // inspired
    int usingDPArray(int n)
    {
        // instead of recursing we just have an array that stores the values at each step
        int arr[n + 1];
        arr[0] = 1; // these are like out base cases
        arr[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        return arr[n];
    }
};