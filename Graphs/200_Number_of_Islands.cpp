/*BFS*/
// TC: O(N*M)
// SC: O(M*N)
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                queue<pair<int, int>> q;
                q.push({i, j});

                grid[i][j] = 'f';
                int dir[][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;

                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int X = x + dir[i][0];
                        int Y = y + dir[i][1];
                        if (X < 0 || Y < 0 || X == grid.size() || Y == grid[0].size() || grid[X][Y] != '1')
                            continue;
                        q.push({X, Y});
                        grid[X][Y] = 'f';
                    }
                }
            }
        }
    }
    return count;
}

/*DFS*/
// TC: O(N*M)
// SC: O(M*N)
void dfs(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != '1')
        return;
    grid[i][j] = 'f';
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}