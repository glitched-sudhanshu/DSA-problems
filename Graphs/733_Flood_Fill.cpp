/*BFS*/
// TC: O(N*M)
// SC: O(M*N)
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    if (image[sr][sc] == color)
        return image;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int dir[][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int parent = image[sr][sc];
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        image[x][y] = color;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int X = x + dir[i][0];
            int Y = y + dir[i][1];
            if (X < 0 || Y < 0 || X == image.size() || Y == image[0].size() || image[X][Y] != parent)
                continue;
            q.push({X, Y});
        }
    }
    return image;
}

/*DFS*/
// TC: O(N*M)
// SC: O(M*N)
void dfs(vector<vector<int>> &image, int i, int j, int color, int parent)
{
    if (i < 0 || j < 0 || i == image.size() || j == image[0].size() || image[i][j] != parent)
        return;
    image[i][j] = color;
    dfs(image, i + 1, j, color, parent);
    dfs(image, i, j - 1, color, parent);
    dfs(image, i - 1, j, color, parent);
    dfs(image, i, j + 1, color, parent);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    if (image[sr][sc] == color)
        return image;
    dfs(image, sr, sc, color, image[sr][sc]);
    return image;
}