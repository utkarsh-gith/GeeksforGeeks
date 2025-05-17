class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj)
    {

        queue<int> q;
        q.push(0);

        vector<bool> visited(adj.size(), false);
        visited[0] = true;

        vector<int> res;

        while (!q.empty())
        {
            int s = q.front();
            q.pop();
            res.push_back(s);

            for (auto &it : adj[s])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }

        return res;
    }
};