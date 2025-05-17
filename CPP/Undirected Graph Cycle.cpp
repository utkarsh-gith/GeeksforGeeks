// Using BFS

class Solution {
  public:
    bool isCycleBFS(int vertex, vector<vector<int>>& adjList, vector<bool>& visited){
        map<int,int> parent;
        parent[vertex] = -1;
        visited[vertex] = true;
        
        queue<int> q;
        q.push(vertex);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto neighbour : adjList[node]){
                if(visited[neighbour] == true && neighbour != parent[node]){
                    return true;
                }else if(!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(vector<int> edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(V, false);
        
        for(int i = 0;i < V; i++){
            if(!visited[i]){
                bool ans = isCycleBFS(i, adjList, visited);
                if(ans == true){
                    return true;
                }
            }
        }
        
        return false;
    }
};

// Using DFS

class Solution {
  public:
    bool isCycleDFS(int vertex, int parent, vector<vector<int>>& adjList, vector<bool>& visited){
        visited[vertex] = true;
        for(int neighbour : adjList[vertex]){
            if(!visited[neighbour]){
                bool cycle = isCycleDFS(neighbour, vertex, adjList, visited);
                if(cycle == true){
                    return true;
                }
            }
            else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(vector<int> edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(V, false);
        
        for(int i = 0;i < V; i++){
            if(!visited[i]){
                bool cycle = isCycleDFS(i, -1, adjList, visited);
                if(cycle == true){
                    return true;
                }
            }
        }
        
        return false;
    }
};