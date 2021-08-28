/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/
int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    if(n<=1) return -1;
    int fp = A[A[0]];
    int sp = A[0];
    while(fp != sp)
    {
        sp = A[sp];
        fp = A[A[fp]];
    }
    fp = 0;
    while(fp != sp)
    {
        fp = A[fp];
        sp = A[sp];
    }
    return sp;
}

