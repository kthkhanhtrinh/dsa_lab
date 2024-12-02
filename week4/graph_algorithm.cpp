Adjacency *BFS(int v)
{
    // v is a vertex we start BFS
    vector<bool> visited(V, false);
    queue<int> q;
    Adjacency *traversal = new Adjacency();;
    
    visited[v] = true;
    q.push(v);
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        traversal->push(curr);
        
        int numNeighbors = adj[curr].getSize();
        for (int i = 0; i < numNeighbors; ++i) {
            int neighbor = adj[curr].getElement(i);
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return traversal;
}

Adjacency *DFS(int v)
{
    vector<bool> visited(V, false); 
    Adjacency* traversal = new Adjacency(); 
    stack<int> s; 

    s.push(v);

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        if (!visited[curr]) {
            visited[curr] = true;
            traversal->push(curr);

            int numNeighbors = adj[curr].getSize();
            for (int i = numNeighbors - 1; i >= 0; --i) { 
                int neighbor = adj[curr].getElement(i);
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

    return traversal;
    
}
/// @brief ///////////////////////////////
/// @param v 
/// @param visited 
/// @param recStack 
/// @return 
bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
    visited[v] = true;
    recStack[v] = true;

    for (int neighbor : adj[v]) {
        if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack)) {
            return true;
        }
        else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool isCyclic() {
    vector<bool> visited(V, false);   
    vector<bool> recStack(V, false); 

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, recStack)) {
                return true;
            }
        }
    }

    return false;
}
///////////////////////////////////////
//Heling functions
void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;

    int numNeighbors = adj[v].getSize();
    for (int i = 0; i < numNeighbors; ++i) {
        int neighbor = adj[v].getElement(i);
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, Stack);
        }
    }

    Stack.push(v);
}


void topologicalSort() {
    stack<int> Stack;           
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

////////////////////////////////////////////
// Some helping functions

int getGraphSize(int** graph) {
    int size = 0;
    while (graph[size] != NULL) {
        size++;
    }
    return size;
}

int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

int Dijkstra(int** graph, int src, int dst) {
    int n = getGraphSize(graph); 
    int dist[n];               
    bool visited[n];         

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;     
        visited[i] = false;    
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;    
        
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist[dst];
}
/////////////////////////////////
int numberOfFriendGroups(vector<vector<int>>& friends) {
    int n = friends.size(); 
    vector<bool> visited(n, false);
    int friendGroups = 0;

    auto dfs = [&](int person, auto& dfsRef) -> void {
        visited[person] = true;
        for (int friendId : friends[person]) {
            if (!visited[friendId]) {
                dfsRef(friendId, dfsRef);
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) { 
            ++friendGroups; 
            dfs(i, dfs);    
        }
    }

    return friendGroups;
}
