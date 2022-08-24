/*Loop*/
// TC: O(log4(n))
// SC: O(1)
bool isPowerOfFour(int n)
{
    if (!n)
        return false;
    while (n % 4 == 0)
        n /= 4;
    return n == 1;
}

/*Bit manipulation*/
// TC: O(1)
// SC: O(1)
bool isPowerOfFour(int n)
{
    if (n <= 0) 
        return false;
    int bits = (int)log2(n) + 1;
    if ((n & (n - 1)) == 0 && ((bits & 1) == 1))
        return true;
    return false;
}
