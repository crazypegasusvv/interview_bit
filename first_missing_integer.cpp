/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
*/
int Solution::firstMissingPositive(vector<int> &a) {
    int n = a.size();
    int nmax1 = n +5;
    for(int i=0;i<n;i++)
    {
        if(a[i]<1 || a[i]>n) 
        {
            a[i]=nmax1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==nmax1 || a[i]==-nmax1)
        {
            continue;
        }
        int val = abs(a[i]);
        a[val-1]= -abs(a[val-1]);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            return i+1;
        }
    }
    return n+1;
}

