/*Hash map*/
//TC: O(N)
//SC O(26) ~ O(1)
int firstUniqChar(string s)
{
    int c[27] = {0};
    for (int i = 0; i < s.size(); i++)
        c[s[i] - 'a']++;
    for (int i = 0; i < s.size(); i++)
    {
        if (c[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}