// if there are n vertices we can have n * (n - 1) / 2 edges
// num of undirected graphs = pow(2, edges)

class Solution
{
public:
    long long count(int n)
    {
        long long edges = n * (n - 1) / 2;
        return pow(2, edges);
    }
};