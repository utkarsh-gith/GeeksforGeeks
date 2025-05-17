class Solution
{
public:
    int minCost(vector<int> &height)
    {
        int n = height.size();

        if (n == 1)
        {
            return 0;
        }

        if (n == 2)
        {
            return abs(height[0] - height[1]);
        }

        int n1 = 0;
        int n2 = abs(height[0] - height[1]);

        for (int i = 2; i < n; i++)
        {
            int n3 = n1 + abs(height[i] - height[i - 2]);
            int n4 = n2 + abs(height[i] - height[i - 1]);
            int n5 = min(n3, n4);
            n1 = n2;
            n2 = n5;
        }

        return n2;
    }
};