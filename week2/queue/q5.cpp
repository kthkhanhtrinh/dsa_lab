// iostream, vector and queue are included
// Hint: use breadth-first-search

int secondsToBeRotten(vector<vector<int>>& grid) {
  int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> rottenQueue;
    int freshCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                rottenQueue.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int time = 0;

    while (!rottenQueue.empty() && freshCount > 0) {
        int size = rottenQueue.size();
        for (int i = 0; i < size; i++) {
            // auto [x, y] = rottenQueue.front();
            int x = rottenQueue.front().first;
            int y = rottenQueue.front().second;
            rottenQueue.pop();

            for (size_t j = 0; j < directions.size(); j++) {
                int dx = directions[j].first;
                int dy = directions[j].second;                
                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; 
                    freshCount--; 
                    rottenQueue.push({newX, newY});
                }
            }
        }
        time++;
    }

    return freshCount == 0 ? time : -1;
    
}