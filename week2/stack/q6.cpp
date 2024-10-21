bool canEatFood(int maze[5][5], int fx, int fy){
    stack<Node> path;
    path.push(Node(0, 0));
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    visited[0][0] = true;
    
    while (!path.empty()) {
        int x = path.top().x;
        int y = path.top().y;
        int dir = path.top().dir;
        if (x == fx && y == fy) return true;
        if (dir < 4) {
            path.top().dir += 1;
            if (dir == 0) { 
                if (x - 1 >= 0 && maze[x - 1][y] == 1
                    && visited[x - 1][y] == false) {
                    path.push(Node(x - 1, y));
                    visited[x - 1][y] = true;
                }
            } else if (dir == 1) {
                if (y - 1 >= 0 && maze[x][y - 1] == 1
                    && visited[x][y - 1] == false) {
                    path.push(Node(x, y - 1));
                    visited[x][y - 1] = true;
                }
            } else if (dir == 2) {
                if (x + 1 < 5 && maze[x + 1][y] == 1
                    && visited[x + 1][y] == false) {
                    path.push(Node(x + 1, y));
                    visited[x + 1][y] = true;
                }
            } else if (dir == 3) {
                if (y + 1 < 5 && maze[x][y + 1] == 1
                    && visited[x][y + 1] == false) {
                    path.push(Node(x, y + 1));
                    visited[x][y + 1] = true;
                }
            }
        } else {
            path.pop();
            visited[x][y] = false;
        }
    }
    return false;

}