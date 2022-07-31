// TC: O(W1*W2*w)
// SC: O(N)

bool isSubset(unordered_map<char, int> p, string c)
{
    for (int i = 0; i < c.size(); i++)
    {
        if (p[c[i]] > 0)
            p[c[i]]--;
        else
            return false;
    }
    return true;
}

// TC: O(N*l)
// SC: O(N)
vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    vector<string> ans;
    for (int i = 0; i < words1.size(); i++)
    {
        unordered_map<char, int> m;
        string w = words1[i];
        for (int k = 0; k < w.size(); k++)
            m[w[k]]++;
        bool isSub = true;
        for (int j = 0; j < words2.size(); j++)
        {
            if (!isSubset(m, words2[j]))
            {
                isSub = false;
                break;
            }
        }
        if (isSub)
            ans.push_back(words1[i]);
    }
    return ans;
}

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    vector<string> ans;
    vector<int> v(26, 0);
    for (string w : words2)
    {
        vector<int> temp(26, 0);
        for (char c : w)
            temp[c - 'a']++;
        for (int k = 0; k < 26; ++k)
            v[k] = max(v[k], temp[k]);
    }
    for (string w : words1)
    {
        vector<int> temp(26, 0);
        for (char c : w)
            temp[c - 'a']++;
        int k = 0;
        for (; k < 26; ++k)
            if (temp[k] < v[k])
                break;
        if (k == 26)
            ans.push_back(w);
    }
    return ans;
}

// TC: O(W1 + W2)
// SC: O(N)
vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    vector<string> ans;
    string b = "";
    for (auto B : words2)
    {
        string temp;
        sort(B.begin(), B.end());
        set_union(B.begin(), B.end(), b.begin(), b.end(), back_inserter(temp));
        b = temp;
    }
    vector<string> res;
    for (auto a : words1)
    {
        string t = a;
        sort(t.begin(), t.end());
        if (includes(t.begin(), t.end(), b.begin(), b.end()))
        {
            res.push_back(a);
        }
    }
    return res;
}