class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(V);
        for(vector<int>& edge : edges){
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }
        
        queue<int> q;
        vector<int> dist(V, -1);
        
        q.push(0);
        dist[0] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(pair<int, int>& neighbour : adjList[node]){
                int distance = dist[node] + neighbour.second;
                if(dist[neighbour.first] == -1 || distance < dist[neighbour.first]){
                    dist[neighbour.first] = distance;
                    q.push(neighbour.first);
                }
            }
        }
        
        return dist;
    }
};