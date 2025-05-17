class Solution
{
public:
    int minimizeCost(int k, vector<int> &arr)
    {
        int n = arr.size();

        if (n == 1)
        {
            return 0;
        }

        if (n == 2)
        {
            return abs(arr[0] - arr[1]);
        }

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        dp[1] = abs(arr[0] - arr[1]);

        for (int i = 2; i < n; i++)
        {
            int j = min(i, k);
            while (j > 0)
            {
                dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
                j--;
            }
        }

        return dp[n - 1];
    }
};