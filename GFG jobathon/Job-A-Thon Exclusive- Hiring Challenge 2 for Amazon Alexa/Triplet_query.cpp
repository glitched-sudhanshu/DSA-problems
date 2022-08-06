/*
in this question we are creating the adjanceny list first. Then,
for each node we go its neighbours, if it is of same color and it is not visited, then call dfs for that neighbour.
Else if it is not of the same color we just add it to the set of neighbour nodes for that node.
*/
void dfs(int node, vector<int> adj[], string &col, vector<int> &vis, set<char> &st)
{
    vis[node] = 1;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr] && col[nbr] == col[node])
        {
            dfs(nbr, adj, col, vis, st);
        }
        else
        {
            st.insert(col[nbr]);
        }
    }
}

vector<string> solve(int N, int M, int Q, string col, vector<vector<int>> &Edge, vector<string> &query)
{

    int dp[26][26][26] = {0};
    vector<int> adj[N];
    for (auto it : Edge)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(N, 0);

    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            set<char> st;
            dfs(i, adj, col, vis, st);

            for (auto it1 : st)
            {
                for (auto it2 : st)
                {
                    dp[col[i] - 'a'][it1 - 'a'][it2 - 'a'] = 1;
                }
            }
        }
    }

    vector<string> ans;

    for (int i = 0; i < Q; i++)
    {
        int a = query[i][0] - 'a';
        int b = query[i][1] - 'a';
        int c = query[i][2] - 'a';
        if (dp[a][b][c] || dp[b][a][c] || dp[c][b][a])
        {
            ans.push_back("YES");
        }
        else
            ans.push_back("NO");
    }
    return ans;
}

// https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-2-for-amazon-alexa/problems/#