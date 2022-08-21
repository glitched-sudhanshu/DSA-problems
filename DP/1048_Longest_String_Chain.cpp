/*Founding LIS*/
// TC: O(N*N*l) l:length of words
// SC: O(N)
/*
Here we are just finding the LIS with just a slight change in the check condition:
compare function:- that both strings should differ by only one character
*/
static bool comp(string s1, string s2)
{
    return s1.length() < s2.length();
}

bool compare(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;
    int i = 0, j = 0;
    while (i < s1.size())
    {
        if (j < s2.size() && s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (i == s1.size() && j == s2.size())
        return true;
    return false;
}

int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(), comp);
    int n = words.size();
    vector<int> dp(n, 1);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (compare(words[i], words[j]))
                dp[i] = max(1 + dp[j], dp[i]);
        }
        maxi = max(dp[i], maxi);
    }
    return maxi;
}

// TODO:
// Check if any other more optimized solution