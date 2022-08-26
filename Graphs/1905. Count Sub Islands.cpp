/*dfs*/
//TC:O(N*M)
//SC:O(N*M)
bool dfs(vector<vector<int>> &g1, vector<vector<int>> &g2, int i, int j)
{
    if (i < 0 || j < 0 || i >= g1.size() || j >= g1[0].size() || g2[i][j] != 1)
        return true;
    if (g1[i][j] != 1)
        return false;
    g2[i][j] = 0;
    bool a = dfs(g1, g2, i + 1, j);
    bool b = dfs(g1, g2, i - 1, j);
    bool c = dfs(g1, g2, i, j - 1);
    bool d = dfs(g1, g2, i, j + 1);
    return (a & b & c & d);
}

int countSubIslands(vector<vector<int>> &g1, vector<vector<int>> &g2)
{
    int m = g1.size();
    int n = g1[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g2[i][j] == 1)
            {
                if (dfs(g1, g2, i, j))
                    count++;
            }
        }
    }
    return count;
}

/*bfs*/
//TC:O(N*M)
//SC:O(N*M)
bool bfs(vector<vector<int>> &g1, vector<vector<int>> &g2, int i, int j)
{
    bool ans = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    g2[i][j] = 0;
    int dir[][4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (g1[x][y] != 1)
            ans = false;
        q.pop();
        for (int K = 0; K < 4; K++)
        {
            int X = x + dir[K][0];
            int Y = y + dir[K][1];
            if (X < 0 || Y < 0 || X >= g2.size() || Y >= g2[0].size() || g2[X][Y] != 1)
                continue;
            q.push({X, Y});
            g2[X][Y] = 0;
        }
    }
    return ans;
}
