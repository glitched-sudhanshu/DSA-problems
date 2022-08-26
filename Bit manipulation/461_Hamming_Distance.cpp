// TC: O(logN) ~ O(log31) ~O(1)
// SC: O(1)
int hammingDistance(int x, int y)
{
    int count = 0;
    while (max(x, y) > 0)
    {
        if (((x & 1) ^ (y & 1)))
            count++;
        x = x >> 1;
        y = y >> 1;
    }
    return count;
}

// TC: ~O(1)
// SC: O(1)
int hammingDistance(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 31; i++)
    {
        int m = (1 << i);
        if (((x & m) ^ (y & m)))
            count++;
    }
    return count;
}