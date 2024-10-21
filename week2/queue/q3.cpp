void bfs(vector<vector<int>> graph, int start) {
    int n = graph.size(); 
    vector<bool> visited(n, false); 
    queue<int> q;  

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++) {
            int adjNode = graph[node][i];
            if (!visited[adjNode]) {
                visited[adjNode] = true;
                q.push(adjNode);
            }
        }
    }
}