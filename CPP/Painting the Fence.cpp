// Make two categories same and diff
// Start from n = 1 and initialise same as 0 and diff as k
// total becomes k
// as moving to n = 2 and further
// same becomes equal to previous diff
// diff becomes equal to total * (k - 1)

class Solution
{
public:
    int countWays(int n, int k)
    {

        if (n == 1)
        {
            return k;
        }

        int n2 = k;
        int t = k;

        for (int i = 2; i <= n; i++)
        {
            int n1 = n2;
            n2 = t * (k - 1);
            t = n1 + n2;
        }

        return t;
    }
};