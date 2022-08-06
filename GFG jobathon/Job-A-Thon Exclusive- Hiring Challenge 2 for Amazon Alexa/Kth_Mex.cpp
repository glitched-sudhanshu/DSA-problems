/*Using set*/
int kthMex(int N, int k, int A[])
{
    unordered_set<int> arr;
    for (int i = 0; i < N; i++)
    {
        arr.insert(A[i]);
    }
    int count = 0;
    int temp = 0;
    while (count <= k)
    {
        if (!arr.count(temp))
        {
            count++;
        }
        if (count == k)
            break;
        temp++;
    }
    return temp;
}

/*Array*/
//Why 2*N?
//Because if the size of array is N and since K can have maxi value as N. In worst case, (0->N-1) all elements are present and if K = N your answer will be 2*N.
//So while creating a map of array you dont need to check for the numbers greater than 2*N because even for K=N they would not be responsible for MEX, it will lie before that number.
int arr[2*N + 1] = {0};
    for(int i=0; i<N; i++)
    {
        if(A[i] <= 2*N) arr[A[i]] = 1;
    }
    for(int i=0; i<=2*N; i++)
    {
        if(arr[i] == 0) k--;
        
        if(k==0) return i;
    }
    return N;

// https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-2-for-amazon-alexa/problems/#