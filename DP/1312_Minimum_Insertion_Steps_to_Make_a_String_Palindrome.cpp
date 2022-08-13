/*Space optimized tabulation*/
// TC: O(N*M)
// SC: 2*O(M)
int helpLongestCommonSubsequence(string t1, string t2)
{
    int n = t1.size(), m = t2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int i = 0; i <= m; i++)
        prev[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (t1[i - 1] == t2[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(cur[j - 1], prev[j]);
        }
        prev = cur;
    }
    return prev[m];
}

int helpLongestPalindromeSubseq(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return helpLongestCommonSubsequence(s, t);
}

int minInsertions(string s)
{
    int h = helpLongestPalindromeSubseq(s);
    return s.size() - h;
}

/*
If we know the length of the longest pallindromic subseq in the given string then we have to take care of the rest of the characters that are not the part of the longest pallindromic subseq. Since we only need the number of insertions and insertions can be done anywhere in the string. We just need the length of the longest pallindromic subseq and rest of the characters would be added in that string, that is string.size() - length(LPS)
*/