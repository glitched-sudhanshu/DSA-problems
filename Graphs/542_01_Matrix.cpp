vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                dist[i][j] = 0;
            }
            else
            {
                for (int k = 0; k < rows; k++)
                {
                    for (int l = 0; l < cols; l++)
                    {
                        if (matrix[k][l] == 0)
                        {
                            int dist_01 = abs(k - i) + abs(l - j);
                            dist[i][j] = min(dist[i][j], abs(k - i) + abs(l - j));
                        }
                    }
                }
            }
        }
    }
    return dist;
}

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
                q.push({i, j});
            else
                mat[i][j] = -1;
        }
    }

    int dir[][4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int level = 0;
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

                if (newx < 0 || newy < 0 || newx >= m || newy >= n || mat[newx][newy] != -1)
                    continue;

                mat[newx][newy] = level;
                q.push({newx, newy});
            }
        }
    }
    return mat;
}
