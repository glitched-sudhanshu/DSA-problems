/*Priority queue*/
// TC: NlogN
// SC: ~2*O(N)
int minSetSize(vector<int> &arr)
{
    int n = arr.size();
    priority_queue<int> q;
    vector<int> v(1e5 + 1, 0);
    for (auto n : arr)
        v[n]++;
    for (int i = 0; i < 1e5 + 1; i++)
    {
        if (v[i] > 0)
            q.push(v[i]);
    }
    int sum = 0;
    int set = 0;
    while (sum < (n / 2))
    {
        int freq = q.top();
        q.pop();
        sum += freq;
        set++;
    }
    return set;
}

/*Map and Counting sort*/
// TC: O(N)
// SC: O(N)
int minSetSize(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> m;
    for (auto n : arr)
        m[n]++;
    vector<int> v(n + 1, 0);
    for (auto it : m)
        v[it.second]++;
    int ans = 0, removed = 0, half = n / 2, freq = n;
    while (removed < half)
    {
        ans += 1;
        while (v[freq] == 0)
            --freq;
        removed += freq;
        --v[freq];
    }
    return ans;
}