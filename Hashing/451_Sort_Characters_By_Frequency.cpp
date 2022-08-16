/*Using STL*/
//TC: O(logN) + O(N) ~ O(logN)
//SC: O(N)
string frequencySort(string s)
{

    int cnt[128] = {};
    for (char c : s)
        cnt[c] += 1;
    sort(s.begin(), s.end(), [&](char a, char b)
         { return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b); });
    return s;
}

/*Hashmap*/
//TC: O(26*logN) + O(N) ~ O(N)
//SC: O(N) + O(26)
string frequencySort(string s)
{
    unordered_map<char, int> freq;           // for frequency of characters
    priority_queue<pair<int, char>> maxheap; // maxheap according to frequency of characters
    for (char c : s)
        freq[c]++;
    for (auto it : freq)
        maxheap.push({it.second, it.first}); // heap will be constructed on the basis of frequency
    s = "";
    while (!maxheap.empty())
    {
        s += string(maxheap.top().first, maxheap.top().second); // frequency times the character
        maxheap.pop();
    }
    return s;
}