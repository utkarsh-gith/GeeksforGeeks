// Using Prim's Algo

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // visited array to mark nodes that are part of MST
        vector<bool> visited(V, false);

        // MST weight sum
        int wt = 0;

        // Start from node 0, with weight 0
        pq.push({0, 0});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int weight = top.first;
            int node = top.second;
            // If already visited, skip it
            if (visited[node]) continue;

            visited[node] = true;
            wt += weight;

            // Explore neighbors
            for (auto &neighbor : adj[node]) {
                int adjNode = neighbor[0];
                int edgeWeight = neighbor[1];

                if (!visited[adjNode]) {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }

        return wt;
    }
};