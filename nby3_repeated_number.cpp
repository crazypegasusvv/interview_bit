/*
N/3 repeat number

Problem Description

You're given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example:

Input: [1 2 3 1 1]
Output: 1 
1 occurs 3 times which is more than 5/3 times.
*/
int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     int n = A.size();
    int frst = INT_MAX,scnd = INT_MAX;
    int cnt1 =0,  cnt2 =0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==frst)
        {
            cnt1++;
        }
        else if(A[i]==scnd)
        {
            cnt2++;
        }
        else if(cnt1==0){
            cnt1++;
            frst = A[i];
        }
        else if(cnt2==0){
            cnt2++;
            scnd = A[i];
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
 cnt1=0; cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==frst) cnt1++;
        if(A[i]==scnd) cnt2++;
    }
    if(cnt1 > n/3) return frst;
    if(cnt2 > n/3) return scnd;
    return -1;
}

