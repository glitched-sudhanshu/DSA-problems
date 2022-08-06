/*Greedy*/
/*
Suppose number of negatives and positives are not equal
negis != posis      or       negis != posis   
-          +                 -          + 
-          +                 -          + 
-          +                 -          + 
-          +                 -          + 
-          -                 -          - 
-          -                 -          - 

in both of these cases the answer will must be a +ve number. Because in 1st case all +ves will be consumed using -ves and left over -negatives will multiple to give +ves. So in this case our will be to minimize those -ves which are multiplied by each other.
That is why after sorting we come from both directions to have the minimum elements in the middle.
And vice versa.

If 
negis == posis
In this case, after sorting if you compute the answer using the same logic as above, it won't work:
-3 -2 5 6
(-3 * 6) & (-2*5) here you are making the bigger positive number more smaller by multiplying it with bigger negative number. Which will leave 5 with -2. Hence result = -10
But
(-3*5) & (-2*6) here result would -12. Since it is known that result would definitely be a negative value then try to uniformly have the product, smaller negatives * bigger positives.
*/
long long maximumMultiple(int N, int A[])
{
    sort(A, A + N);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 0)
            count++;
    }

    //+ves = -ves
    if (2 * count == N)
    {
        reverse(A, (A + N / 2));
    }

    long long maxi = -1e18;
    for (int i = 0; i < N; i++)
    {
        maxi = max(maxi, (long long)A[i] * A[N - i - 1]);
    }
    return maxi;
}

// https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-2-for-amazon-alexa/problems/#