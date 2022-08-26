// agar 0 boundary touch nahi karta to closed hai
/*dfs*/
// TC: O(N*M)
// SC: O(N*M)
bool dfs(vector<vector<int>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 0)
        return true;
    if ((i == 0 || j == 0 || (i == grid.size() - 1) || (j == grid[0].size() - 1)) && grid[i][j] == 0)
        return false;

    grid[i][j] = 1;
    bool a = dfs(grid, i + 1, j);
    bool b = dfs(grid, i - 1, j);
    bool c = dfs(grid, i, j - 1);
    bool d = dfs(grid, i, j + 1);
    return (a & b & c & d);
}

int closedIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                if (dfs(grid, i, j))
                    count++;
            }
        }
    }
    return count;
}

/*bfs*/
// TC: O(N*M)
// SC: O(N*M)
bool bfs(vector<vector<int>> &grid, int i, int j)
{
    bool ans = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    int dir[][4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if ((x == 0 || y == 0 || (x == grid.size() - 1) || (y == grid[0].size() - 1)) && grid[x][y] == 0)
            ans = false;

        grid[x][y] = 1;
        q.pop();
        for (int K = 0; K < 4; K++)
        {
            int X = x + dir[K][0];
            int Y = y + dir[K][1];
            if (X < 0 || Y < 0 || X >= grid.size() || Y >= grid[0].size() || grid[X][Y] != 0)
                continue;
            q.push({X, Y});
        }
    }
    return ans;
}
