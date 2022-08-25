/*Recursive*/
// TC: O(NlogN) + O(M)
// SC: O(M)
bool help(string &rn, string &mag, int n, int m)
{
    if (n == rn.size())
        return 1;
    if (m == mag.size())
        return false;
    if (rn[n] == mag[m])
        return help(rn, mag, n + 1, m + 1);
    return help(rn, mag, n, m + 1);
}

bool canConstruct(string rn, string mag)
{
    if (rn.size() > mag.size())
        return false;
    sort(rn.begin(), rn.end());
    sort(mag.begin(), mag.end());
    return help(rn, mag, 0, 0);
}

/*Two hashmaps*/
// TC: 3*O(N) ~ O(N)
// SC: 2*O(N) ~ O(N)
bool canConstruct(string rn, string mag)
{
    if (rn.size() > mag.size())
        return false;
    unordered_map<char, int> mmag;
    for (auto c : mag)
        mmag[c]++;
    unordered_map<char, int> mrn;
    for (auto c : rn)
        mrn[c]++;
    for (auto it : mrn)
    {
        auto c = it.first;
        if (it.second > mmag[c])
            return false;
    }
    return true;
}

/*Hashmaps*/
// TC: 3*O(N) ~ O(N)
// SC: O(N)
bool canConstruct(string rn, string mag)
{
    if (rn.size() > mag.size())
        return false;
    unordered_map<char, int> mrn;
    for (auto c : rn)
        mrn[c]++;
    for (auto c : mag)
    {
        if (mrn.count(c) > 0)
            mrn[c]--;
    }
    for (auto it : mrn)
    {
        if (it.second > 0)
            return false;
    }
    return true;
}

/*Array*/
// TC: O(N)
// SC: 0(N)
bool canConstruct(string rn, string mag)
{
    if (rn.size() > mag.size())
        return false;
    int mrn[26] = {0};
    for (auto c : rn)
        mrn[c - 'a']++;
    for (auto c : mag)
    {
        mrn[c - 'a']--;
    }
    for (auto it : mrn)
    {
        if (it > 0)
            return false;
    }
    return true;
}
