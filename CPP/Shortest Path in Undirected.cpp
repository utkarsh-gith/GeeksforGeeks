class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        
        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> dist(n, -1);
        
        q.push(src);
        visited[src] = true;
        dist[src] = 0;
        int distance = 1;
        
        while(!q.empty()){
            
            int m = q.size();
            
            for(int i = 0;i < m; i++){
                int node = q.front();
                q.pop();
                
                for(int& neighbour : adj[node]){
                    if(!visited[neighbour]){
                        visited[neighbour] = true;
                        dist[neighbour] = distance;
                        q.push(neighbour);
                    }
                }
            }
            
            distance++;
        }
        
        return dist;
    }
};