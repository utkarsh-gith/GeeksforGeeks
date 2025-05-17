// Using DFS

class Solution {
  public:
    bool isCycleDFS(int vertex, vector<bool>& visited, vector<bool>& dfsVisited, vector<vector<int>> &adjList){
        visited[vertex] = true;
        dfsVisited[vertex] = true;
        
        for(auto& neighbour : adjList[vertex]){
            if(!visited[neighbour]){
                bool cycle = isCycleDFS(neighbour, visited, dfsVisited, adjList);
                if(cycle){
                    return true;
                }
            }else if(dfsVisited[neighbour]){
                return true;
            }
            
        }
        
        dfsVisited[vertex] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(V);
        for(vector<int>& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> visited(V, false);
        vector<bool> dfsVisited(V, false);
        for(int i = 0;i < V; i++){
            if(!visited[i]){
                bool cycle = isCycleDFS(i, visited, dfsVisited, adjList);
                if(cycle){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};