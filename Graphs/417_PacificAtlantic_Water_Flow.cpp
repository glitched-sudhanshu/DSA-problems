/*
1.Naive solution:
    Standard dfs, which means for each point, we check if it can reach both pacific and atlantic,
    for each point, we can possibly check all the rest of points, O(m*n * m*n)

2.A little improvement:
    What about we 4 hash tables, they keep track of all the points we know so far that
        can reach atlantic
        cannot reach atlantic
        can reach pacific
        cannot reach pacific
    It's doable, still hit TLE, although I didn't hit TLE when not submitting the code, but running it using the provided testing environment

3. Dfs:
    If you think normal dfs with 1 visited matrix can solve this. Then that would not be possible. Because there is a node (i,j)

            2
            3
    1   2   5   3   2
            4
            2
    In such a case 5 is a valid node. But if would have being using dfs for its previous row you would have been marked it false. And because of why 5 will also be marked as false.

3.On the other hand, we can consider the flip side
    We can let the pacific and atlantic ocean "flow into" the matrix as much as possible,
    using 2 boolean arrays, one for each ocean.
    The result are the points that are true in both boolean table
    Instead of checking which nodes can share their water to pacific and atlantic we will see nodes in which pacific and atlantic can share there water. And final answer would be the nodes which are common in both of them.
    //TC: O(M*N)
*/
void dfs(vector<vector<int>> &h, unordered_set<string> &vis, int i, int j, int parent)
{

    string s = to_string(i) + "|" + to_string(j);
    if ((i < 0 || j < 0 || i == h.size() || j == h[0].size()) || (h[i][j] < parent) || vis.count(s))
        return;
    vis.insert(s);
    dfs(h, vis, i + 1, j, h[i][j]);
    dfs(h, vis, i - 1, j, h[i][j]);
    dfs(h, vis, i, j + 1, h[i][j]);
    dfs(h, vis, i, j - 1, h[i][j]);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
{
    int m = h.size();
    int n = h[0].size();
    unordered_set<string> pac;
    unordered_set<string> atl;

    vector<vector<int>> ans;

    for (int i = 0; i < m; i++)
    {
        dfs(h, pac, i, 0, h[i][0]);
        dfs(h, atl, i, n - 1, h[i][n - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        dfs(h, pac, 0, i, h[0][i]);
        dfs(h, atl, m - 1, i, h[m - 1][i]);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            string s = to_string(i) + "|" + to_string(j);
            if (pac.count(s) && atl.count(s))
            {
                ans.push_back({i, j});
            }
        }
    }
    return ans;
}
