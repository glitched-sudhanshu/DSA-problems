/*dfs*/
// TC: O(N*M)
// SC: O(N*M)
void dfs(vector<vector<int>> &g, int &count, int i, int j, bool &bound)
{
    if (i < 0 || j < 0 || i > g.size() - 1 || j > g[0].size() - 1)
        return;

    if (g[i][j] == 0)
        return;

    g[i][j] = 0;

    if (i == 0 || j == 0 || i == g.size() - 1 || j == g[0].size() - 1)
        bound |= true;

    count++;

    dfs(g, count, i + 1, j, bound);
    dfs(g, count, i - 1, j, bound);
    dfs(g, count, i, j + 1, bound);
    dfs(g, count, i, j - 1, bound);
}

int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int subCount = 0;
            bool bound = false;
            if (grid[i][j] == 1)
            {
                // dfs call
                dfs(grid, subCount, i, j, bound);
                if (bound == 1)
                    subCount = 0;
                count += subCount;
            }
        }
    }
    return count;
}


/*bfs*/
// TC: O(N*M)
// SC: O(N*M)
int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size(), ans = 0;

    // arrays to traverse in 4-directions
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                bool flag = false; // bool variable to determine land lies on boundary or not
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = 0; // make the value from 1 to 0 so that we need not require visited array
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                    flag = true;
                int temp = 1; // To count the number of cells in a land contribute to this work

                while (!q.empty())
                {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    { // traverse the 4 directions for current cell
                        int x1 = x + dx[k], y1 = y + dy[k];
                        if (x1 >= 0 and x1 < n and y1 >= 0 and y1 < m and grid[x1][y1] == 1)
                        {

                            // if current cell lies on boundary then we can reach the boundary of grid through any of the cell of this land
                            if (x1 == 0 || x1 == n - 1 || y1 == 0 || y1 == m - 1)
                                flag = true;
                            q.push({x1, y1});
                            grid[x1][y1] = 0;
                            temp++;
                        }
                    }
                }

                if (!flag)
                    ans += temp; // If not able to reach boundary then add all cells of the land to answer.
            }
        }
    }
    return ans;
}
