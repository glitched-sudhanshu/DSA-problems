/*DFS*/
// TC: O(M*N)
// SC: O(M*N)
int dfs(vector<vector<int>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
        return 0;
    grid[i][j] = 0;
    int a = dfs(grid, i + 1, j);
    int b = dfs(grid, i - 1, j);
    int c = dfs(grid, i, j - 1);
    int d = dfs(grid, i, j + 1);
    return 1 + a + b + c + d;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int maxi = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                int area = dfs(grid, i, j);
                // int area = bfs(grid, i, j);
                maxi = max(area, maxi);
            }
        }
    }
    return maxi;
}

/*BFS*/
// TC: O(M*N)
// SC: O(M*N)
int bfs(vector<vector<int>> &grid, int i, int j)
{
    int area = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = 0;
    int dir[][4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        area++;
        q.pop();
        for (int K = 0; K < 4; K++)
        {
            int X = x + dir[K][0];
            int Y = y + dir[K][1];
            if (X < 0 || Y < 0 || X >= grid.size() || Y >= grid[0].size() || grid[X][Y] != 1)
                continue;

            q.push({X, Y});
            grid[X][Y] = 0;
        }
    }
    return area;
}