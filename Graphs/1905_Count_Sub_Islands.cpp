/*dfs*/
//TC:O(N*M)
//SC:O(N*M)
void dfs(vector<vector<int>> &g1, vector<vector<int>> &g2, int i, int j, bool &sub)
{
    if (i < 0 || j < 0 || i > g1.size() - 1 || j > g1[0].size() - 1)
        return;

    if (g2[i][j] == 1)
    {
        if (g2[i][j] == 1 && g1[i][j] != 1)
            sub &= false;
        g2[i][j] = 0;
        dfs(g1, g2, i + 1, j, sub);
        dfs(g1, g2, i - 1, j, sub);
        dfs(g1, g2, i, j + 1, sub);
        dfs(g1, g2, i, j - 1, sub);
    }
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
            bool sub = true;
            if (g2[i][j] == 1)
            {
                // call dfs
                dfs(g1, g2, i, j, sub);
                if (sub == true)
                    count++;
            }
        }
    }
    return count;
}



/*bfs*/
//TC:O(N*M)
//SC:O(N*M)
int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2)     {
    int m = g1.size();
    int n = g1[0].size();
    
    int count = 0;
    
    int dir[] = {1, 0, -1, 0, 1};
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(g2[i][j] == 0) continue;
            queue<pair<int,int>> q;
            q.push({i, j});
            bool flag = 1;
            g2[i][j] = 0;
            
            while(!q.empty())
            {
                auto coordi = q.front();
                q.pop();
                int x = coordi.first;
                int y = coordi.second;
                if(g1[x][y] == 0) flag = 0;
                
                for(int k=0; k<4; k++)
                {
                    int nx = x + dir[k];
                    int ny = y + dir[k+1];
                    
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && g2[nx][ny] == 1) {
                        g2[nx][ny] = 0;
                        q.push({nx,ny});
                    }
                }
            }
            if(flag == 1) count++;
        }
    }
    return count;
}
