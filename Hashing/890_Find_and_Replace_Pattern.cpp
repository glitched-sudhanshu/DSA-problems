/*two map approach*/
// TC: O(N*L)
// SC: O(N*L)
vector<string> findAndReplacePattern(vector<string> &words, string p)
{
    vector<string> ans;
    for (auto &w : words)
        if (match(w, p))
            ans.push_back(w);
    return ans;
}
bool match(string &w1, string &w2)
{
    unordered_map<char, char> w1_to_w2, w2_to_w1;
    for (int i = 0; i < size(w1); i++)
        if ((w1_to_w2.count(w1[i]) && w1_to_w2[w1[i]] != w2[i]) ||
            (w2_to_w1.count(w2[i]) && w2_to_w1[w2[i]] != w1[i]))
            return false;
        else
            w1_to_w2[w1[i]] = w2[i],
            w2_to_w1[w2[i]] = w1[i];
    return true;
}

/*single map approach*/
// TC: O(N*L)
// SC: O(N*L)
vector<string> findAndReplacePattern(vector<string> &words, string p)
{
    vector<string> ans;
    for (auto &w : words)
        if (match(w, p))
            ans.push_back(w);
    return ans;
}
bool match(string &w1, string &w2)
{
    unordered_map<char, char> w1_to_w2;
    for (int i = 0; i < size(w1); i++)
        if (w1_to_w2.count(w1[i]) && w1_to_w2[w1[i]] != w2[i])
            return false;
        else
            w1_to_w2[w1[i]] = w2[i];
    bitset<26> visited;
    for (auto &pair : w1_to_w2)
        if (visited[pair.second - 'a'])
            return false;
        else
            visited[pair.second - 'a'] = true;
    return true;
}

/*Normalization - change every word to a specific pattern*/
// for eg jjyas -> aabcd; kkuty -> aabcd; llsul-> aabca
// TC: O(N*L)
// SC: O(N*L)
vector<string> findAndReplacePattern(vector<string> &words, string &pattern)
{
    vector<string> ans;
    string p = normalise(pattern);
    for (auto &w : words)
        if (p == normalise(w))
            ans.push_back(w);
    return ans;
}
string normalise(string w)
{
    unordered_map<char, char> mp;
    char c = 'a';
    for (auto ch : w)
        if (!mp.count(ch))
            mp[ch] = c++;
    for (auto &ch : w)
        ch = mp[ch];
    return w;
}