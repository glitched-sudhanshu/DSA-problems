/*Space optimized tabulation*/
// TC: O(N*N)
// SC: 2*O(N)
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

int longestPalindromeSubseq(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return helpLongestCommonSubsequence(s, t);
}

/*
A pallindrome is a sequence of characters which appears exactly the same if we write them left-to-right or right-to-left.
To check for the longest pallindrome subsequence in a string (if we manually find it), and then if we reverse the string. The pallindromic characters of that string will remain in the same position as in the main string (that is why they are pallindrome).
And all the other characters will loose their original position, else they would have been the part of the pallindromic subseq.
So the common part of the reverse string and the original string is bound to be a pallindrome. And if we find the maximum length of common subseq in both the strings that would be the length of the longest pallindromic subseq in the original string.
*/