class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adjList(V);
        for(vector<int>& edge : edges){
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> st;
        
        dist[src] = 0;
        st.insert({0, src});
        
        while(!st.empty()){
            auto top = *(st.begin());
            
            int distance = top.first;
            int node = top.second;
            
            st.erase(st.begin());
            
            for(auto neighbour : adjList[node]){
                if(distance + neighbour.second < dist[neighbour.first]){
                    auto record = st.find({dist[neighbour.first], neighbour.first});
                    if(record != st.end()){
                        st.erase(record);
                    }
                    
                    dist[neighbour.first] = distance + neighbour.second;
                    st.insert({dist[neighbour.first], neighbour.first});
                }
            }
        }
        
        return dist;
    }
};