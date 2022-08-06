/*bfs*/
// TC: O(n*n)
// SC: O(n*n)
int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size();

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
                q.push({i, j});
    }

    int dir[][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    if (q.size() == 0 || q.size() == (n * n))
        return -1;

    int level = -1;
    while (!q.empty())
    {
        level++;
        int qsize = q.size();
        while (qsize--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dir[i][0];
                int newy = y + dir[i][1];

                if (newx < 0 || newy < 0 || newx >= n || newy >= n || grid[newx][newy] == 1)
                    continue;
                q.push({newx, newy});
                grid[newx][newy] = 1;
            }
        }
    }
    return level;
}

/*dfs*/
// TC:O(m*n*n) m: no of 1s
// SC:O(n*n)
void dfs(vector<vector<int>> &grid, int i, int j, int dist)
{
    if (i < 0 || j < 0 || i == grid.size() || j == grid.size() || (grid[i][j] != 0 && grid[i][j] <= dist))
        return;
    grid[i][j] = dist;
    dfs(grid, i + 1, j, dist + 1);
    dfs(grid, i - 1, j, dist + 1);
    dfs(grid, i, j + 1, dist + 1);
    dfs(grid, i, j - 1, dist + 1);
}

int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                grid[i][j] = 0;
                dfs(grid, i, j, 1);
            }
        }
    }
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] > 1)
                mx = max(mx, grid[i][j] - 1);
        }
    }
    return mx;
}
