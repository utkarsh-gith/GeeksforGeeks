//Using DFS

class Solution {
  public:
    void dfsSort(int node, vector<bool>& visited, stack<int>& st, vector<vector<int>>& adjList){
        visited[node] = true;
        for(auto& neighbour : adjList[node]){
            if(!visited[neighbour]){
                dfsSort(neighbour, visited, st, adjList);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        for(vector<int>& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
        }
        
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i = 0;i < V; i++){
            if(!visited[i]){
                dfsSort(i, visited, st, adjList);
            }
        }
        
        vector<int> sorted;
        while(!st.empty()){
            sorted.push_back(st.top());
            st.pop();
        }
        
        return sorted;
        
    }
};

//Using Kahn's Algo (BFS)
// find indegree of all vertices and insert 0 indegree vertices in queue
// pop the first element in queue
// remove the edges to the neighbours and check the indegree
// if equal to 0 push into queue

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        vector<int> inDegree(V, 0);
        for(vector<int>& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        
        queue<int> q;
        for(int i = 0;i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> sorted;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            sorted.push_back(node);

            for (auto& neighbour : adjList[node]) {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        
        return sorted;
        
    }
};