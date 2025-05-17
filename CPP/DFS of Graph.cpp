class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> &res, vector<vector<int>> &adj, vector<bool> &visited, int node)
    {
        for (int i = 0; i < adj[node].size(); i++)
        {
            int num = adj[node][i];
            if (!visited[num])
            {
                res.push_back(num);
                visited[num] = true;
                dfs(res, adj, visited, num);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>> &adj)
    {
        vector<int> res;
        vector<bool> visited(adj.size());
        visited[0] = true;
        res.push_back(0);

        for (int i = 0; i < adj[0].size(); i++)
        {
            int num = adj[0][i];
            if (!visited[num])
            {
                res.push_back(num);
                visited[num] = true;
                dfs(res, adj, visited, num);
            }
        }

        return res;
    }
};