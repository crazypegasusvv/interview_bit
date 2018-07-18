/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return 1 ( true ).

A = [3,2,1,0,4], return 0 ( false ).

Return 0/1 for this problem
*/
int Solution::canJump(vector<int> &A) 
{
    if(A.size()<2) return 1;
    if(A[0]==0) return 0;
    int cnt=0;
    for(int i=A.size()-2;i>=0;i--)
    {
        cnt++;
        if(A[i]>=cnt) cnt=0;
    }
    return cnt<2;
}
