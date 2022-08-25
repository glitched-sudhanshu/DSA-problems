/*Brainteaser*/
//TC: O(1)
//SC: O(1)
double nthPersonGetsNthSeat(int n)
{
    if (n == 1)
    {
        return (double)n;
    }
    return (1 / (2.0));
}

//since (n-1) persons will take (n-1) seats the probability that the nth seat is left is (1/2).