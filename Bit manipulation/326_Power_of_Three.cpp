/*Loop*/
// TC: O(log3(n))
// SC: O(1)
bool isPowerOfThree(int n)
{
    if (!n)
        return false;
    while (n % 3 == 0)
        n /= 3;
    return n == 1;
}

/*Max modulo*/
// TC: O(1)
// SC: O(1)
bool isPowerOfThree(int n)
{
    int maxi = pow(3, floor(log(INT_MAX) / log(3)));
    return ((n > 0) && (maxi % n) == 0);
}