/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
      long long sum = 0;
       long long squareSum = 0;
       long long temp;
     for (int i = 0; i < A.size(); i++) {
           temp = A[i];
           sum += temp;
           sum -= (i + 1);
           squareSum += (temp * temp);
           squareSum -= ((long long)(i + 1) * (long long)(i + 1));
       }
       // sum = A - B
       // squareSum = A^2 - B^2 = (A - B)(A + B)
       // squareSum / sum = A + B
       squareSum /= sum;
 
       // Now we have A + B and A - B. Lets figure out A and B now. 
       int on= (int) ((sum + squareSum) / 2);
       int B = squareSum - on;
 
       vector<int> ret;
       ret.push_back(on);
       ret.push_back(B);
       return ret;
}

