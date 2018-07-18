/*
 * Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
 Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations. 
 Look at the example for more details.
 
 Example :
 
 Input : 'aba'
 Output : 2
 
 The order permutations with letters 'a', 'a', and 'b' : 
 aab
 aba
 baa
 The answer might not fit in an integer, so return your answer % 1000003
 
 NOTE: 1000003 is a prime number
 NOTE: Assume the number of characters in string < 1000003
 */
//function for computing (x^y)%p
long long modexp(long long x,long long y,long long p)
{
    long long  res=1;
    
    while(y>0)
    {
        if(y&1) res=(res*x)%p;
        x=(x*x)%p;
        y=y>>1;
    }
    
    return res;
}
//storing the factorials of all numbers upto string length modulo 1000003 
void modFact(int f[],int n)
{
    for(int i=2;i<n;i++)
    {
        f[i]=(i*f[i-1])%1000003;
    }
}
//finding the number of strings which come before the string with starting letter C in lexicographic order
long int rk(int f[],char C,string s,int st)
{
    int j=0;
    
    //since there are 256 characters we could declare an array of the same size
    int cnt[256]={0};
    
  
    for(int i=st;i<s.length();i++)
    {
        //counting the occurences of each character
        cnt[s[i]]++;
        
        //counting the no. of characters which are greater than the current character C
        if(C>s[i]) j++;
    }
    
    if(j==0) return 0;
    
    //sorting in decreasing order
    sort(cnt,cnt+256,greater<int>());
    
    long long int k=j*f[s.length()-st-1];
    
    //from fermats'little theorem m|(a^m)-a where m is prime
    //here 1000003 is a prime 
    //so m|(a^-1)-(a^m-2)
    //dividing k with f[cnt[i]] doesn't help so we use fermats theorem
    for(int i=0;i<256 && cnt[i]>1;i++) k=(k*modexp(f[cnt[i]],1000001,1000003))%1000003;
    
    return k%1000003;
}
int findRank(string A) 
{
    long long int l=A.length(),r=0;
   
    int f[l+1];
    memset(f,0,l+1);
    
    //tabulating the factorial values
    f[0]=f[1]=1;
    modFact(f,l+1);
    
    //summing up all the possibilities for strings starting with A[i]
    for(int i=0;i<l-1;i++) 
    {
        long int rnk=rk(f,A[i],A,i);
        r=(r+rnk)%1000003;
    }
    
    return (r+1)%1000003;
}
int main()
{
   string A="cabacb";
    //to calculate rank of string A amongst its permutations sorted lexicographically modulo 1000003
   cout<<findRank(A);
}
