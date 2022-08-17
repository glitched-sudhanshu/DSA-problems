/*map and set*/
// TC: O(S)
// SC: O(S)
// S: Sum of length of words in "words"
int uniqueMorseRepresentations(vector<string> &words)
{
    string morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    unordered_set<string> st;
    for (auto w : words)
    {
        string s = "";
        for (auto c : w)
        {
            s += morse[c - 'a'];
        }

        st.insert(s);
    }
    return st.size();
}